/*************************************************************************
	> File Name: CountDownLatch.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月24日 星期一 18时11分46秒
 ************************************************************************/

#ifndef MUDUO_BASE_COUNTDOWNLATCH_H
#define MUDUO_BASE_COUNTDOWNLATCH_H

#include <muduo/base/Condition>
#include <muduo/base/Mutex.h>
#include <boost/noncopyable.hpp>

namespace muduo
{
class CountDownLatch : boost::noncopyable
{
public:
    explicit CountDownLatch(int count);

    void wait();

    void countDown();

    int getCount() const;
    
private:
    mutable MutexLock mutex_;
    Condition condition_;
    int count_;
};
}
#endif
