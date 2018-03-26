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

unsigned _hash(void* ptr){
    unsigned res = (long) ptr * 11 % 46591;
    //printf("hash %ld at %d to %d\n", (long)ptr, usage_q, res);
    return res;
}

class SchBlock{
    public:
        void* obj;
        std::mutex lock;
        int next;
        unsigned key;

        SchBlock(void* ptr){
            obj = ptr;
            key = _hash(ptr);
        }
};

boost::lockfree::queue<SchBlock*> **queues;

void _contention_manage_begin(SchBlock& sb){

    SchUnit* unit = sch_map.get(sb.key);
    if(unit == NULL)unit = sch_map.create(sb.key, sb.key % num_q);

    sb.next = unit->getQueue();

    sb.lock.lock();

    queues[sb.next]->push(&sb);

    sb.lock.lock();

    sb.lock.unlock();
}

void _contention_manage_abort(SchBlock& sb, int flag){}

void _dispatch(int id){
    SchBlock* block;

    while(!terminate){
        if(queues[id]->pop(block)){

            SchUnit* unit = sch_map.get(block->key);
            if(unit == NULL)unit = sch_map.create(block->key, block->key % num_q);

            unit->add();

            block->lock.unlock();
            //std::cout << "get:" << block->key << " " << sch_map.get(block->key)->getCount() << " " << sch_map.get(block->key)->getQueue() << std::endl;
        }

    }
}

void _update(){
    int interval = 5000;

    while(!terminate){
        usleep(interval);

        //std::cout << "update" << std::endl;

        std::map<int, std::vector<unsigned>, std::greater<int>>* view = sch_map.getOrderedView();

        bool forward =  true;
        int idx = 0;

        for(const auto& it : *view){
            int count = it.first;
            for(const auto& vit : it.second){
                //:wstd::cout << vit << " " << count <<std::endl;
                auto item = sch_map.get(vit);
                item->setQueue(idx);
                item->reset();
                if(forward){
                    idx++;
                    if(idx == num_q){
                        idx--;
                        forward = false;
                    }
                }
                else{
                    idx--;
                    if(idx < 0){
                        idx = 0;
                        forward = true;
                    }
                }
            }
        }

        delete view;
    }
}

void _init(){
    contention_time = time(NULL);
    queues = (boost::lockfree::queue<SchBlock*> **) malloc(sizeof(void*) * num_q);

    terminate = false;

    std::thread* dispatchers[num_q][per_q];

    std::thread* updater;

    for(int i = 0; i < num_q; ++i){
        queues[i] = new boost::lockfree::queue<SchBlock*>(size_q);
    }

    updater = new std::thread(_update);
    updater->detach();

    for(int i = 0; i < num_q; ++i){
        for(int j = 0; j < per_q; ++j){
            dispatchers[i][j] = new std::thread(_dispatch, i);
        }
    }

    for(int i = 0; i < num_q; ++i){
        for(int j = 0; j < per_q; ++j){
            dispatchers[i][j]->detach();
        }
    }

}

void _end(){
    terminate = true;

    delete [] queues;
}

#endif
