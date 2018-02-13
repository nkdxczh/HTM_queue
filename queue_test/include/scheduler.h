#ifndef  SCHEDULER_H
#define  SCHEDULER_H

#include <boost/lockfree/queue.hpp>
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <unordered_map>
#include <time.h>

#include "schunit.h"

#define num_q 3
#define per_q 4

SchMap sch_map;

bool terminate = false;
int size_q = 100;
int usage_q = num_q;

/*int capacity_abort;
  int conflict_abort;
  int other_abort;
  int gl_abort;
  int gl_count;
  int htm_count;
  std::mutex lock;*/

std::mutex contention_lock;
int contention_time;
int contention_queue;

int contention_level[num_q];
int capacity_level[num_q];

class SchBlock{
    public:
        void* obj;
        std::mutex lock;
        int next;

        SchBlock(void* ptr){
            obj = ptr;
        }
};

boost::lockfree::queue<SchBlock*> **queues;

unsigned _hash(void* ptr){
    unsigned res = (long) ptr * 11 % 46591;
    //printf("hash %ld at %d to %d\n", (long)ptr, usage_q, res);
    return res;
}

void _contention_manage_begin(SchBlock& sb){
    sb.next = sch_map.get(_hash(sb.obj), usage_q)->getQueue();

    sb.lock.lock();

    queues[sb.next]->push(&sb);

    sb.lock.lock();

    sb.lock.unlock();
}

void _contention_manage_abort(SchBlock& sb, int flag){
    /*if(flag == 2){
        sb.conflict = false;
        return;
    }

    sb.abort_time = time(NULL);
    contention_level[sb.next] += 1;
    if(sb.start_time > contention_time){
        contention_lock.lock();
        if(sb.start_time > contention_time){
            contention_time = sb.abort_time;
            contention_queue = rand() % usage_q;
        }
        contention_lock.unlock();
    }
    sb.next = contention_queue;*/
}

void _dispatch(int id){
    SchBlock* block;

    while(!terminate){
        if(queues[id]->pop(block)){
            block->lock.unlock();

            sch_map.get(_hash(block->obj), usage_q)->add();
        }

    }
}


void _init(){
    contention_time = time(NULL);
    queues = (boost::lockfree::queue<SchBlock*> **) malloc(sizeof(void*) * num_q);

    std::thread* dispatchers[num_q][per_q];

    for(int i = 0; i < num_q; ++i){
        queues[i] = new boost::lockfree::queue<SchBlock*>(size_q);
    }

    for(int i = 0; i < usage_q; ++i){
        for(int j = 0; j < per_q; ++j){
            dispatchers[i][j] = new std::thread(_dispatch, i);
        }
    }

    for(int i = 0; i < usage_q; ++i){
        for(int j = 0; j < per_q; ++j){
            dispatchers[i][j]->detach();
        }
    }

    terminate = false;
}

void _end(){
    terminate = true;

    delete [] queues;
}

#endif
