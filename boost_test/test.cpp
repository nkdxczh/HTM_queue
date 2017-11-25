#include "transactions.h"
#include "scheduler.h"
#include <iostream>

int sum = 0;

/*void work(int id){
    _contention_manage();

    for(int i = 0; i < 1000; ++i){
        sum += 1;
    }

}*/

int main()
{
    int thread_num = 100;
    _init();

    /*std::thread* threads[thread_num];

    for(int i = 0; i < thread_num; ++i){
        threads[i] = new std::thread(work, i);
    }

    for(int i = 0; i < thread_num; ++i){
        threads[i]->join();
    }*/


    for(int i = 0; i < thread_num; ++i){
        TM_BEGIN
            for(int i = 0; i < 100000; ++i){
                sum += 1;
            }
        TM_END;
    }

    std::cout << sum << std::endl;

    _end();
}
