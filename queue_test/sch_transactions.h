#ifndef SCH_TRANSACTIONS_H
#define SCH_TRANSACTIONS_H

#include <mutex>
#include "scheduler.h"

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

#define ENQUEUE 2
#define TRIES 1

#define SCH_TM_BEGIN(ptr)				        \
{												\
    int enqueue = ENQUEUE;                      \
    int tries = 0;      						\
    SchBlock sb(ptr);                      \
    while(1){									\
        if(tries <= 0 && enqueue > 0){          \
            tries = TRIES;                      \
            enqueue--;                          \
            _contention_manage_begin(sb);       \
        }                                       \
        while(IS_LOCKED(gl_lock)){				\
            __asm__ ( "pause;" );				\
        } 										\
        int status = _xbegin();					\
        if(status == _XBEGIN_STARTED){			\
            if(IS_LOCKED(gl_lock)){				\
                _xabort(30);					\
            }									\
            break;								\
        }										\
        if(status & _XABORT_CODE(30)){			\
            gl_abort++;							\
        } else if(status & _XABORT_CAPACITY){	\
            _contention_manage_abort(sb, 0);    \
            capacity_abort++;					\
        } else if(status & _XABORT_CONFLICT){	\
            _contention_manage_abort(sb, 1);    \
            conflict_abort++;					\
        } else{									\
            _contention_manage_abort(sb, 2);    \
            other_abort++;						\
        }										\
        tries--;								\
        if(enqueue <= 0 && tries <= 0){			\
            gl_lock.lock();			            \
            break;								\
        }										\
    }

# define SCH_TM_END								\
    if(tries > 0 || enqueue > 0){			    \
        _xend();								\
        htm_count++;							\
    } else {									\
        gl_lock.unlock();                       \
        gl_count++;								\
    }											\
};

#define SCH_TM_INIT _init();

#define SCH_TM_CLOSE _end();

#endif // TRANSACTIONS_H
