/*************************************************************************
	> File Name: Condition.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月17日 星期一 12时35分27秒
 ************************************************************************/

class Condition : boost::noncopyable
{
public:
    explicit Condition(MutexLock& mutex)
        :mutex_(mutex)
    {  pthread_cond_init(&pcond_, NULL); }

    ~Condition() { pthread_cond_destory(&pcond_); }

    void wait() { pthread_cond_wait(&pcond_, mutex_.getPthreadMutex()); }

    void notify() {pthread_cond_signam(&pcond_); }

    void notifyAll() { pthread_cond_broadcast(&pcond_); }

private:
    MutexLock& mutex_;
    pthread_cond_t pcond_;

};


/*Condition 使用示例，condition_必须先于mutex_之前构造*/

class CountDownLatch
{
public:
    CountDownLatch(int count) 
        : mutex_(), condition_(mutex_), count_(count)    //初始化顺序与成员声明保持一致
    {  }   

private:
    mutable MutexLock mutex_;
    Condition condition_;
    int count_;
}

