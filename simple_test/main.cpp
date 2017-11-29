#include <iostream>
#include <immintrin.h>

#include <x86intrin.h>
#include <cpuid.h>

#include <unistd.h>

#include "transactions.h"

#include <thread>
#include <stdlib.h>

using namespace std;

int capacity_abort;
int conflict_abort;
int other_abort;
int gl_abort;
int gl_count;
int htm_count;

THREAD_MUTEX_T lock;

#define bit_RTM (1 << 11)

int value;

int check_rtm_support() {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_max(0, NULL) >= 7) {
        __cpuid_count(7, 0, eax, ebx, ecx, edx);
        if (ebx & bit_RTM) return 1;
    }
    return 0;
}

void do_work(){
    for(int i = 0; i < 200000; i++) {
        TM_BEGIN
            value++;
        TM_END
    }
}

int HTM_test() {
    value = 0;
if(check_rtm_support())
	cout<<"Nop";
else
	cout<<"Yep";

	int thread_num = 100;
	std::thread* threads[thread_num];
	for(int i = 0; i < thread_num; ++i){
		threads[i] = new std::thread(do_work);
	}
	for(int i = 0; i < thread_num; ++i){
		threads[i]->join();
	}

    cout << "Value " << value << endl;
    cout << "HTM Count " << htm_count << endl;
    cout << "Lock Count " << gl_count << endl;
    cout << "Capacity Aborts " << capacity_abort << endl;
    cout << "Conflict Aborts " << conflict_abort << endl;
    cout << "Other Aborts " << other_abort << endl;
    cout << "Lock Aborts " << gl_abort << endl;
}
