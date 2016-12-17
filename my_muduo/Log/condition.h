/*************************************************************************
	> File Name: condition.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 16时58分23秒
 ************************************************************************/

#ifndef _CONDITION_H
#define _CONDITION_H

#include <thread>
#include <assert.h>
#include <stdio.h>
#include <pthread.h>

namespace netlib
{
    class Condition
    {
    public:
        Condition(phread_mutex_t *mutex)
            :mutex_(mutex)
        {
            pthread_cond_init(&cond_, NULL);
        }

        ~Condition()
        {
            pthread_cond_destory(&cond_);
        }

        void wait()
        {
            int ret = pthread_cond_wait(&cond_, mutex_);
            assert(ret == 0);
        }

        void notify()
        {
            int ret = pthread_cond_signal(&cond_);
            assert(ret == 0);
        }

        void notifyAll()
        {
            int ret = pthread_cond_broadcast(&cond_);
            assert(ret == 0);
        }

    private:
        pthread_mutex_t *mutex_;
        pthread_cond_t cond_;
    };
}
#endif
