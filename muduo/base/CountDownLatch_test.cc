#include <../base/CountDownLatch.h>
#include <../base/Thread.h>
#include <boost/bind.hpp>

#include <vector>
#include <stdio.h>

using namespace muduo;

CountDownLatch latch_(1);

void Func()
{
    latch_.wait();
    printf("Thread ID=%d, namespace=%s\n", CurrentThread::tid(), CurrentThread::name());
}

int main()
{
    Thread t1(boost::bind(Func), "Thread1");
    THread t2(boost::bind(Func), "Thread2");

    t1.start();
    t2.start();

    printf("main thread running\n")；
    latch_.countDown();   //count为0时唤醒等待线程
    sleep(3);
    printf("main thread runnig, after countDown\n");

    t1.join();
    t2.join();

    return 0;
}
