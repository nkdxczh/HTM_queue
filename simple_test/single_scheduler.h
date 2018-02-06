#ifndef  SCHEDULER_H
#define  SCHEDULER_H

#include <boost/lockfree/queue.hpp>
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <unordered_map>
#include <time.h>

bool terminate = false;
int size_q = 100;
int num_q = 10;
int usage_q = 10;
int delay = 10;

std::mutex contention_lock;
int contention_time;
int contention_queue;

int contention_level;
int capacity_level;

boost::lockfree::queue<std::mutex*> **queues;

class ScheduleBlock{
    public:
    int group;
    int last;
    int next;

    int start_time;
    int abort_time;

    ScheduleBlock(){
        group = -1;
        last = -1;
        next = -1;
    }
};

void _contention_manage_begin(ScheduleBlock& sb){
    std::mutex* m_lock = new std::mutex();

    m_lock->lock();

    if(sb.next == -1)return;
    //sb.next = rand() % usage_q;

    queues[sb.next]->push(m_lock);

    m_lock->lock();

    m_lock->unlock();

    delete m_lock;

    sb.start_time = time(NULL);
}

void _contention_manage_abort(ScheduleBlock& sb, int flag){
    if(flag == 2){
        sb.next = -1;
        return;
    }
    sb.abort_time = time(NULL);
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

void _dispatch(){
    std::mutex* m_lock;
    int tasks = 0;
    int round = 0;
    float low_threshold = 0.1;
    float high_threshold = 0.8;

    while(!terminate){
        for (int i = 0; i < usage_q; ++i){
            if(queues[i]->pop(m_lock)){
                m_lock->unlock();
                tasks++;
            }
        }
        round++;

        usleep(delay);

        if(round > 50){
            if(contention_level <= low_threshold * tasks){
                if(usage_q < num_q)usage_q++;
                else if(delay >= 10) delay -= 10;
            }
            else if(contention_level > high_threshold * tasks){
                if(usage_q > 2)usage_q--;
                else delay += 10;
            }
            contention_level = 0;
        }
    }
}


void _init(){
    contention_time = time(NULL);
    queues = (boost::lockfree::queue<std::mutex*> **) malloc(sizeof(void*) * num_q);
    for(int i = 0; i < num_q; ++i){
        queues[i] = new boost::lockfree::queue<std::mutex*>(size_q);
    }

    terminate = false;
    std::thread dispatcher(_dispatch);
    dispatcher.detach();
}

void _end(){
    terminate = true;

    delete [] queues;
}

#endif
