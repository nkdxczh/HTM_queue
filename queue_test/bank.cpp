#include <iostream>
#include <immintrin.h>

#include <x86intrin.h>
#include <cpuid.h>

#include <unistd.h>

#include "transactions.h"
#include "sch_transactions.h"

#include "account.h"

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

int thread_num = 500;
int tasks = 1000;

int accounts = 5;
float amount = 100000;

Bank* bank;

int check_rtm_support() {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_max(0, NULL) >= 7) {
        __cpuid_count(7, 0, eax, ebx, ecx, edx);
        if (ebx & bit_RTM) return 1;
    }
    return 0;
}

void do_work_lock(){
    for(int i = 0; i < tasks; ++i){
        int op = rand() % 100; 
        if(op < 101){
            int a1 = rand() % accounts;
            int a2 = rand() % accounts;
            while(a2 != a1)a2 = rand() % accounts;
            float amount = float(rand() % 100) / 10;
            int res = bank->transfer(a1, a2, amount);
            //if(res == 0)std::cout << "TRANSFER: " << a1 << "," << a2 << "," << amount << std::endl;
        }
        else{
            std::cout << "SUM: " << bank->sum() << std::endl;
        }
    }
}

void do_work_HTM(){
    for(int i = 0; i < tasks; ++i){
        int op = rand() % 100; 
        if(op < 101){
            int a1 = rand() % accounts;
            int a2 = rand() % accounts;
            while(a2 != a1)a2 = rand() % accounts;
            float amount = float(rand() % 100) / 10;
            int res;
            TM_BEGIN
                res = bank->transfer_lockfree(a1, a2, amount);
            TM_END
            //if(res == 0)std::cout << "TRANSFER: " << a1 << "," << a2 << "," << amount << std::endl;
        }
        else{
            float res;
            TM_BEGIN
                res = bank->sum_lockfree();
            TM_END
            std::cout << "SUM: " << res << std::endl;
        }
    }
}

void do_work_sch_HTM(){
    for(int i = 0; i < tasks; ++i){
        int op = rand() % 100; 
        if(op < 101){
            int a1 = rand() % accounts;
            int a2 = rand() % accounts;
            while(a2 != a1)a2 = rand() % accounts;
            float amount = float(rand() % 100) / 10;
            int res;
            SCH_TM_BEGIN(bank->get(a1))
                res = bank->transfer_lockfree(a1, a2, amount);
            SCH_TM_END
            //if(res == 0)std::cout << "TRANSFER: " << a1 << "," << a2 << "," << amount << std::endl;
        }
        else{
            float res;
            SCH_TM_BEGIN(bank->get(0))
                res = bank->sum_lockfree();
            SCH_TM_END
            std::cout << "SUM: " << res << std::endl;
        }
    }
}

int main() {

    bank = new Bank(accounts);
    struct timeval start;
    struct timeval end;

    bank->progagate(amount);

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


    capacity_abort = 0;
    conflict_abort = 0;
    other_abort = 0;
    gl_abort = 0;
    gl_count = 0;
    htm_count = 0;

    bank->progagate(amount);

    SCH_TM_INIT
    gettimeofday(&start, NULL);

    for(int i = 0; i < thread_num; ++i){
        threads[i] = new std::thread(do_work_sch_HTM);
    }
    for(int i = 0; i < thread_num; ++i){
        threads[i]->join();
    }

    gettimeofday(&end, NULL);
    SCH_TM_CLOSE

    cout << (end.tv_sec - start.tv_sec) * 1000000 + ((int)end.tv_usec - (int)start.tv_usec) << endl;

    //cout << "Value " << value << endl;
    cout << "HTM Count " << htm_count << endl;
    cout << "Lock Count " << gl_count << endl;
    cout << "Capacity Aborts " << capacity_abort << endl;
    cout << "Conflict Aborts " << conflict_abort << endl;
    cout << "Other Aborts " << other_abort << endl;
    cout << "Lock Aborts " << gl_abort << endl;
}
