#include <iostream>
#include <immintrin.h>

#include <x86intrin.h>
#include <cpuid.h>

#include <unistd.h>

#include "transactions.h"

using namespace std;

int capacity_abort;
int conflict_abort;
int other_abort;
int gl_abort;
int gl_count;
int htm_count;

THREAD_MUTEX_T lock;

#define bit_RTM (1 << 11)

int check_rtm_support() {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_max(0, NULL) >= 7) {
        __cpuid_count(7, 0, eax, ebx, ecx, edx);
        if (ebx & bit_RTM) return 1;
    }
    return 0;
}

int main() {
    int value = 0;
if(check_rtm_support())
	cout<<"Nop";
else
	cout<<"Yep";
    //#pragma omp parallel for num_threads(1)
    for(int i = 0; i < 20000000; i++) {
        TM_BEGIN
            value++;
        TM_END
    }

    cout << "Value " << value << endl;
    cout << "HTM Count " << htm_count << endl;
    cout << "Lock Count " << gl_count << endl;
    cout << "Capacity Aborts " << capacity_abort << endl;
    cout << "Conflict Aborts " << conflict_abort << endl;
    cout << "Other Aborts " << other_abort << endl;
    cout << "Lock Aborts " << gl_abort << endl;
}
