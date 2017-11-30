#ifndef  SCHEDULER_H
#define  SCHEDULER_H

#include <boost/lockfree/queue.hpp>
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <unordered_map>
#include <time.h>

#define num_q 6

bool terminate = false;
int size_q = 100;
int usage_q = num_q;
int delay[num_q];

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

boost::lockfree::queue<std::mutex*> **queues;

class ScheduleBlock{
    public:
        int group;
        int last;
        int next;

        int start_time;
        int abort_time;

        bool conflict;

        ScheduleBlock(){
            group = -1;
            last = -1;
            next = -1;
            conflict = false;
        }
};

void _contention_manage_begin(ScheduleBlock& sb){
    if(sb.next == -1)sb.next = rand() % usage_q;
    if(!sb.conflict)return;

    std::mutex* m_lock = new std::mutex();

    m_lock->lock();

    queues[sb.next]->push(m_lock);

    m_lock->lock();

    m_lock->unlock();

    delete m_lock;

    sb.start_time = time(NULL);
}

void _contention_manage_abort(ScheduleBlock& sb, int flag){
    if(flag == 2){
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
    sb.next = contention_queue;
}

void _dispatch(int id){
    std::mutex* m_lock;
    int tasks = 0;
    int round = 0;
    float low_threshold = 0.1;
    float high_threshold = 0.3;

    while(!terminate){
        if(queues[id]->pop(m_lock)){
            m_lock->unlock();
            tasks++;
        }
        else{
            continue;
        }

        usleep(delay[id]);

        if(tasks > 100){
            //std::cout << "adjust" << std::endl;
            if(contention_level[id] <= low_threshold * tasks){
                //std::cout << "too soft" << std::endl;
                if(delay[id] >= 1) delay[id] -= 1;
                //else if(usage_q < num_q)usage_q++;
            }
            else if(contention_level[id] > high_threshold * tasks){
                //std::cout << "too tight " << id << std::endl;
                delay[id] += 1;
                //if(usage_q > 2)usage_q--;
            }
            contention_level[id] = 0;
        }
    }
}


void _init(){
    contention_time = time(NULL);
    queues = (boost::lockfree::queue<std::mutex*> **) malloc(sizeof(void*) * num_q);

    std::thread* dispatchers[num_q];

    for(int i = 0; i < num_q; ++i){
        queues[i] = new boost::lockfree::queue<std::mutex*>(size_q);
    }

    for(int i = 0; i < usage_q; ++i){
        delay[i] = 0;
        dispatchers[i] = new std::thread(_dispatch, i);
    }

    for(int i = 0; i < usage_q; ++i){
        dispatchers[i]->detach();
    }

    terminate = false;
}

void _end(){
    terminate = true;

    delete [] queues;
}

#endif
