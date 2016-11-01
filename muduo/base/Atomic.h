/*************************************************************************
	> File Name: Atomic.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月23日 星期日 23时49分49秒
 ************************************************************************/

#ifndef MUDUO_BASE_ATOMIC_H
#define MUDUO_BASE_ATOMIC_H

#include <boost/noncopyable.hpp>
#include <stdint.h>

namespace muduo
{
namespace detail
{
template<typename T>
class AtomicIntegerT : boost noncopyable
{
public:
    AtomicIntegerT()
        : value_(0)
    {  }

    T get()
    {
        return __sync_val_compare_and_swap(&value_, 0, 0);  //原子操作，当value_=0时，将0赋给value_,返回value改变前的值
    }

    T getAndAdd(T x)
    {
        return __sync_fetch_and_add(&value_, x); //原子操作，先得到返回值，然后自增
    }

    /*得到原值后加原值，再给原值自增*/
    T addAndGet(T x)
    {
        return getAndAdd(x) + x;
    }


    T incrementAndGet()
    {

        return addAndGet(1);
    }
    
    T decrementAndGet()
    {
        return addAndGet(-1);
    }

    /*得到原值后自增*/
    void add(T x)
    {
        getAndAdd(x);
    }
    
    /*自增*/
    void increment()
    {
        incrementAndGet();
    }

    void decrement()
    {
        decrementAndGet();
    }

    T getAndSet(T newValue)
    {
        return __sync_lock_test_and_set(&value_, newValue); //将ptr设为value并返回ptr操作之前的值
    }

private:
    volatile T value_;
};
}
}
#endif
