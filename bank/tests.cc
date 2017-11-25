#include <iostream>
#include <ctime>
#include "config_t.h"
#include "tests.h"
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <mutex>
#include <sys/time.h>

#include "simplemap.h"
#include <chrono>

#include <immintrin.h>
#include <x86intrin.h>
#include <cpuid.h>
#include <unistd.h>
#include "transactions.h"
#include "scheduler.h"

std::mutex* locks;
simplemap_t<int, float> *map;
int iters;
int key_max;
int* durations;
int* seeds;

void deposit(int id){
    srand(seeds[id]);
    int account1 = (int) (rand() % (key_max + 1));
    int account2 = (int) (rand() % (key_max + 1));

    while(account2 == account1)account2 = (int) (rand() % (key_max));

    float left = 0;

    TM_BEGIN
        left = map->lookup(account1).first;
        float fund = ((float) rand() / (float) (RAND_MAX)) * left;
        fund = (float)((int) (fund*100)) / (float)(100);
        map->update(account1, left - fund);
        map->update(account2, map->lookup(account2).first + fund);
    TM_END
}

float balance(int id){
    float sum = 0;
    TM_BEGIN
        sum = 0;
        for(int i  = 0; i <= key_max; ++i){
            sum += map->lookup(i).first;
        }
    TM_END
    return sum;
}

void do_work(int id, int iters){
    struct timeval start;
    gettimeofday(&start, NULL);
    for(int i = 0; i < iters; ++i){
        if(rand() % 10 < 10)deposit(id);
        else balance(id);
    }
    struct timeval end;
    gettimeofday(&end, NULL);
    durations[id] = (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec);
}


void deposit_lock(int id){
    srand(seeds[id]);
    int account1 = (int) (rand() % (key_max));
    int account2 = (int) (rand() % (key_max));

    while(account2 == account1)account2 = (int) (rand() % (key_max));

    float left = 0;

    while(true){
        locks[account1].lock();
        if(locks[account2].try_lock())break;
        else locks[account1].unlock();
        std::this_thread::yield();
    }

    left = map->lookup(account1).first;
    float fund = ((float) rand() / (float) (RAND_MAX)) * left;
    fund = (float)((int) (fund*100)) / (float)(100);
    map->update(account1, left - fund);
    map->update(account2, map->lookup(account2).first + fund);

    locks[account1].unlock();
    locks[account2].unlock();
}

float balance_lock(int id){
    float sum = 0;
    for(int i = 0; i < key_max; ++i)locks[i].lock();
    for(int i  = 0; i <= key_max; ++i){
        sum += map->lookup(i).first;
    }
    for(int i = 0; i < key_max; ++i)locks[i].unlock();
    return sum;
}

void do_work_lock(int id, int iters){
    struct timeval start;
    gettimeofday(&start, NULL);
    for(int i = 0; i < iters; ++i){
        if(rand() % 10 < 10)deposit_lock(id);
        else balance_lock(id);
    }
    struct timeval end;
    gettimeofday(&end, NULL);
    durations[id] = (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec);
}

void printer(int k, float v) {
    std::cout<<"<"<<k<<","<<(float)((int)(v * 100)) / 100<<">"<< std::endl;
}

void run_custom_tests(config_t& cfg) {
    srand(time(0));
    seeds = new int[cfg.threads];
    for(int i  = 0; i < cfg.threads; i++){
        seeds[i] = rand();
    }

    map = new simplemap_t<int, float>();

    locks = new std::mutex[cfg.key_max];
    iters = cfg.iters;
    key_max = cfg.key_max;
    durations = new int[cfg.threads];  

    float init_fund = int(1000 / (cfg.key_max + 1));
    for(int i  = 0; i < cfg.key_max; i++){
        map->insert(i, init_fund);
    }
    map->insert(cfg.key_max, 1000 - cfg.key_max * init_fund);

    struct timeval start;
    struct timeval end;

    std::thread* threads[cfg.threads];  
    float sumTime = 0;

    //--------------------HTM test--------------------- 
    gettimeofday(&start, NULL);

    for(int i = 0; i < cfg.threads; ++i){
        threads[i] = new std::thread(do_work, i, iters);
    }

    for(int i = 0; i < cfg.threads; ++i){
        threads[i]->join();
    }

    gettimeofday(&end, NULL);

    for(int i = 0; i < cfg.threads; ++i){
        sumTime += (float)durations[i];
    }

    if(cfg.show){
        std::cout << "----- HTM experiment -----"<< std::endl;
        std::cout << "final balance: " << balance(-1) << std::endl;
        std::cout << "total time: " << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << std::endl;
        std::cout << "average time: " << sumTime/cfg.threads << std::endl;
    }
    else{
        std::cout << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << std::endl;
    }

    //--------------------lock test--------------------- 
    gettimeofday(&start, NULL);

    for(int i = 0; i < cfg.threads; ++i){
        threads[i] = new std::thread(do_work_lock, i, iters);
    }

    for(int i = 0; i < cfg.threads; ++i){
        threads[i]->join();
    }

    gettimeofday(&end, NULL);

    sumTime = 0;
    for(int i = 0; i < cfg.threads; ++i){
        sumTime += (float)durations[i];
    }

    if(cfg.show){
        std::cout << "----- lock experiment -----"<< std::endl;
        std::cout << "final balance: " << balance(-1) << std::endl;
        std::cout << "total time: " << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << std::endl;
        std::cout << "average time: " << sumTime/cfg.threads << std::endl;
    }
    else{
        std::cout << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << std::endl;
    }


    threads[0] = new std::thread(do_work, 0, cfg.threads * iters);
    threads[0]->join();

    if(cfg.show){
        std::cout << "----- single thread experiment -----"<< std::endl;
        std::cout << "final balance: " << balance(-1) << std::endl;
        std::cout << "total time: " << durations[0] << std::endl;
    }
    else{
        std::cout << durations[0] << std::endl;
    }

    for(int i  = 0; i < cfg.key_max; i++){
        map->remove(i);
    }

    delete map;
    delete[] durations;
    delete[] seeds;

}

void test_driver(config_t &cfg) {
    _init();
    run_custom_tests(cfg);
    _end();
}
