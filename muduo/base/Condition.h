/*************************************************************************
	> File Name: Condition.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月24日 星期一 00时40分15秒
 ************************************************************************/

#ifndef MUDUO_BASE _CONDITION_H
#define MUDUO_BASE _CONDITION_H

namespace muduo
{
class Condition : boost::noncopyable
{
public:
    explicit Condition(MutexLock& mutex)
        : mutex_(mutex)
    {
        MCHECK(pthread_cond_init(&pcond(), NULL);
    }

    ~Condition()
    {
        MECHECK(pthread_cond_destory(&pcond_));    
    }

    void wait()
    {
        MutexLock::UnassignGuard_ug(mutex_);
        MCHECK(pthread_cond_wait(&pcond_, mutex_. getPthreadMutex()));
    }

    bool waitForSeconds(double seconds);

    void notify()
    {
        MCHECK(pthread_cond_signal(&pcond_));    
    }

    void notifyAll()
    {
        MECHECK(pthread_cond_broadcast(&pcond_););
    }
private:
    MutexLock& mutex_;
               pthread_cond_t pcond_;
}
}
#endif
