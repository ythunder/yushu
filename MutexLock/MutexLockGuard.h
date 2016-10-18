/*************************************************************************
	> File Name: MutexLockGuard.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月13日 星期四 22时42分34秒
    > 封装临界区的进入和退出，即加锁解锁。
 ************************************************************************/

#include "MutexLock.h"

class MutexLockGuard : boost::noncopyable
{
public:
    explicit MutexLockGuard(MutexLock &mutex)
        :mutex_(mutex)
    { mutex_.lock(); }

    ~MutexLockGuard()
    { mutex_.unlock(); }
private:
    MutexLock& mutex_;
};

#define MutexLockGuard(x) static(false, "missing mutex guard var name")

/*最后一行宏定义防止程序中出现如下错误
 *void doit()
 *{
 *  MutexLockGuard(mutex);  //遗漏变量名，产生临时对象又立即销毁，结果没有锁住临界区
 *}
 * */
