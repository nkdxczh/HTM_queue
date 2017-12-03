#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <pthread.h>

extern int capacity_abort;
extern int conflict_abort;
extern int other_abort;
extern int gl_abort;
extern int gl_count;
extern int htm_count;

#define IS_LOCKED(lock)					*((volatile int*)(&lock)) != 0
#define THREAD_MUTEX_T                      pthread_mutex_t
#define THREAD_MUTEX_INIT(lock)             pthread_mutex_init(&(lock), NULL)
#define THREAD_MUTEX_LOCK(lock)             pthread_mutex_lock(&(lock))
#define THREAD_MUTEX_UNLOCK(lock)           pthread_mutex_unlock(&(lock))

extern THREAD_MUTEX_T o_lock;

# define TM_BEGIN									\
    {												\
        int tries = 5;      						\
        while(1){									\
            while(IS_LOCKED(o_lock)){					\
                __asm__ ( "pause;" );				\
            } 										\
            int status = _xbegin();					\
            if(status == _XBEGIN_STARTED){			\
                if(IS_LOCKED(o_lock)){				\
                    _xabort(30);					\
                }									\
                break;								\
            }										\
            if(status & _XABORT_CODE(30)){			\
                gl_abort++;							\
            } else if(status & _XABORT_CAPACITY){	\
                capacity_abort++;					\
            } else if(status & _XABORT_CONFLICT){	\
                conflict_abort++;					\
            } else{									\
                other_abort++;						\
            }										\
            tries--;								\
            if(tries <= 0){							\
                pthread_mutex_lock(&o_lock);			\
                break;								\
            }										\
        }

# define TM_END										\
        if(tries > 0){								\
            _xend();								\
            htm_count++;							\
        } else {									\
            pthread_mutex_unlock(&o_lock);			\
            gl_count++;								\
        }											\
    };

#endif // TRANSACTIONS_H
