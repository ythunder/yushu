/*************************************************************************
	> File Name: Counter.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月13日 星期四 22时51分21秒
 ************************************************************************/

class Counter : boost::noncopyable
{
public:
    Counter() : value_(0) {}
    int64_t value() const;
    int64_t getAndIncrease();

private:
    int64_t value_;
    mutable MutexLock mutex_;
};

int64_t Counter::value() const
{
    MutexLockGuard lock(mutex_);
    return value_;
}

int64_t Counter::getAndIncrease()
{
    MutexLockGuard lock(mutex_);
    int64_t ret = value_++;
    return ret;
}

