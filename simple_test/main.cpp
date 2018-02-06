#include <iostream>
#include <immintrin.h>

#include <x86intrin.h>
#include <cpuid.h>

#include <unistd.h>

#include "transactions.h"
#include "sch_transactions.h"
#include "scheduler.h"

#include <thread>
#include <stdlib.h>

#include <sys/time.h>
#include <unistd.h>

using namespace std;

int capacity_abort;
int conflict_abort;
int other_abort;
int gl_abort;
int gl_count;
int htm_count;

THREAD_MUTEX_T o_lock;
std::mutex gl_lock;

#define bit_RTM (1 << 11)
#define v_num 8

int value[v_num];
int thread_num = 32;
int thread_num = 4;
int tasks = 2000;

int check_rtm_support() {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_max(0, NULL) >= 7) {
        __cpuid_count(7, 0, eax, ebx, ecx, edx);
        if (ebx & bit_RTM) return 1;
    }
    return 0;
}

void do_work_HTM(){
    for(int i = 0; i < tasks; i++) {
        int k = rand() % v_num;
        TM_BEGIN
            for(int j = 0; j < 2000; ++j)value[k]++;
        TM_END
    }
}

void do_work_sch_HTM(){
    for(int i = 0; i < tasks; i++) {
        int k = rand() % v_num;
        SCH_TM_BEGIN
            for(int j = 0; j < 2000; ++j)value[k]++;
        SCH_TM_END
    }
}

int main() {
    for(int i = 0; i < v_num; ++i)value[i] = 0;

    struct timeval start;
    struct timeval end;

    /*if(check_rtm_support())
        cout<<"Nop";
    else
        cout<<"Yep";*/

    /*gettimeofday(&start, NULL);

    for(int i = 0; i < thread_num * tasks; i++) {
            value++;
    }

    gettimeofday(&end, NULL);

    cout << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << endl;*/

    std::thread* threads[thread_num];

    gettimeofday(&start, NULL);

    for(int i = 0; i < thread_num; ++i){
        threads[i] = new std::thread(do_work_HTM);
    }
    for(int i = 0; i < thread_num; ++i){
        threads[i]->join();
    }

    gettimeofday(&end, NULL);

    cout << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << endl;

    //cout << "Value " << value << endl;
    cout << "HTM Count " << htm_count << endl;
    cout << "Lock Count " << gl_count << endl;
    cout << "Capacity Aborts " << capacity_abort << endl;
    cout << "Conflict Aborts " << conflict_abort << endl;
    cout << "Other Aborts " << other_abort << endl;
    cout << "Lock Aborts " << gl_abort << endl;

    for(int i = 0; i < v_num; ++i)value[i] = 0;

    capacity_abort = 0;
    conflict_abort = 0;
    other_abort = 0;
    gl_abort = 0;
    gl_count = 0;
    htm_count = 0;

    _init();
    gettimeofday(&start, NULL);

    for(int i = 0; i < thread_num; ++i){
        threads[i] = new std::thread(do_work_sch_HTM);
    }
    for(int i = 0; i < thread_num; ++i){
        threads[i]->join();
    }

    gettimeofday(&end, NULL);
    _end();

    cout << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << endl;

    //cout << "Value " << value << endl;
    cout << "HTM Count " << htm_count << endl;
    cout << "Lock Count " << gl_count << endl;
    cout << "Capacity Aborts " << capacity_abort << endl;
    cout << "Conflict Aborts " << conflict_abort << endl;
    cout << "Other Aborts " << other_abort << endl;
    cout << "Lock Aborts " << gl_abort << endl;
}
