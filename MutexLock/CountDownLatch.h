/*************************************************************************
	> File Name: CountDownLatch.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月17日 星期一 13时02分28秒
 ************************************************************************/

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
};
