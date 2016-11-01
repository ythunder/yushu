/*************************************************************************
	> File Name: Mutex.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月24日 星期一 14时08分44秒
 ************************************************************************/

#ifndef MUDUO_BASE_MUTEX_H
#define MUDUO_BASE_MUTEX_H

#include <../muduo/base/CurrentThread.h>
#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>


/??/
#ifdef NDEBUG
extern void __assert_perror_fail(int errnum, 
                                const char *file,
                                unsigned int line,
                                cost char *function)
    __THROW_attribute__((__noreturn__));
__END_DECLS
#endif

#define MCHECK(ret) ({__typedef__(ret) errnum = (ret);     \
                     if(__builtin_expect(errnum !=0, 0))   \
                     __assert_perror_fail(errnum, __FILE__,__LINE__, __func__);})

#else

#define MECHCK(ret) ({__typedef__(ret) errnum = (ret);    \
                     assert(errnum == 0); (void) errnum;})

#endif


class MutexMock : boost::noncopyable
{
public:
    MutexLock()
        :holder_(0)
    {
        MUCHECK(pthread_mutex_init(&mutex_, NULL));
    }

    ~MutexLock()
    {
        assert(holder_ == 0);
        MUCHECK(pthread_mutex_init(&mutex_, NULL));
    }

    bool isLockedByThisThread() const
    {
        return holder_ == CurrentThread::tid();
    }

    void assertLocked() const
    {
        assert(isLockedByThisThread());
    }

    void lock()
    {
        MCHECK(pthread_mutex_lock(&mutex_));
        assignHolder();
    }

    void unlock()
    {
        unassignHolder();
        MECHCK(pthread_mutex_unlock(&mutex_));
    }

private:
    friend class Condition;
    class UnassignGaurd : boost::noncopyable
    {
    public:
        UnassignGaurd(MutexLock& owner)
            :onwer_(onwer)
        {
            owner_.unassignHolder();
        }
        ~UnassignGaurd()
        {
            owner_.assignHolder();
        }
    private:
        MutexLock& owner_;
    };

void unassignHolder()
{
    holder_ = 0;
}
void assignHolder()
{
    holder_ = CurrentThread::tid();
}

pthread_mutex_t mutex_;
pid_t holder_;
};

class MutexLockGuard : boost::noncopyable
{
public:
    explicit MutexLockGuard(MutexLock& mutex)
        :mutex_(mutex)
    {
        mutex_.lock();
    }
    ~MutexLockGuard()
    {
        mutex_.unlock();
    }
private:
    MutexLock& mutex_;
}


#endif

