/*************************************************************************
	> File Name: mutex.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月18日 星期二 23时01分10秒
 ************************************************************************/

#ifndef _MUTEX_H
#define _MUTEX_H

#include <thread>
#include <pthread.h>
#include <assert.h>
#include <stdio.h>

namespace netlib
{
    class Mutex
    {
    public:
        Mutex()
        {
            pthread_mutex_init(&mutex_, NULL);
        }

        ~Mutex()
        {
            pthread_mutex_destroy(&mutex_);
        }

        void lock()
        {
            int ret = pthread_mutex_lock(&mutex_);
            assert(ret == 0);
        }

        void unlock()
        {
            int ret = pthread_mutex_unlock(&mutex_);
            assert(ret == 0);
        }

        pthread_mutex_t* getMutex()
        {
            return &mutex_;
        }
    private:
        pthread_mutex_t mutex_;
    };
}
#endif
