#ifndef SCH_TRANSACTIONS_H
#define SCH_TRANSACTIONS_H

#include <mutex>

extern int capacity_abort;
extern int conflict_abort;
extern int other_abort;
extern int gl_abort;
extern int gl_count;
extern int htm_count;
extern std::mutex gl_lock;

/*#define IS_LOCKED(lock)					*((volatile int*)(&lock)) != 0
#define THREAD_MUTEX_T                      pthread_mutex_t
#define THREAD_MUTEX_INIT(lock)             pthread_mutex_init(&(lock), NULL)
#define THREAD_MUTEX_LOCK(lock)             pthread_mutex_lock(&(lock))
#define THREAD_MUTEX_UNLOCK(lock)           pthread_mutex_unlock(&(lock))
*/

#define SCH_TM_BEGIN(ptr)							\
{												\
    int enqueue = 2;                            \
    bool finish = false;                        \
    ScheduleBlock sb;                           \
    while(1){									\
        _contention_manage_begin(sb);           \
        int tries = 2;      						\
        while(1){                               \
            while(IS_LOCKED(gl_lock)){				\
                __asm__ ( "pause;" );				\
            } 										\
            int status = _xbegin();					\
            if(status == _XBEGIN_STARTED){			\
                if(IS_LOCKED(gl_lock)){				\
                    tries--;                        \
                    _xabort(30);					\
                }									\
            }										\
            if(status & _XABORT_CODE(30)){			\
                gl_abort++;							\
                continue;                           \
            } else if(status & _XABORT_CAPACITY){	\
                _contention_manage_abort(sb, 0);    \
                capacity_abort++;					\
                continue;                           \
            } else if(status & _XABORT_CONFLICT){	\
                _contention_manage_abort(sb, 1);    \
                conflict_abort++;					\
                continue;                           \
            } else{									\
                _contention_manage_abort(sb, 2);    \
                other_abort++;						\
                continue;                           \
            }										\
            tries--;								\
            if(tries <= 0){							\
                if(enqueue <= 0)gl_lock.lock();			            \
            }										                                       

# define SCH_TM_END								\
            if(_xtest()){							\
                _xend();							\
                htm_count++;						\
            } else {								\
                gl_lock.unlock();                   \
                gl_count++;							\
            }										\
            finish = true;                      \
            break;                                  \
        }                                           \
        if(finish)break;                            \
        enqueue--;                                  \
    }                                           \
};

#endif // TRANSACTIONS_H
