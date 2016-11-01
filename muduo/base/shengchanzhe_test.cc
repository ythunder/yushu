#include <../base/Mutex.h>
#include <../base/Thread.h>
#include <boost/bind.hpp>
#include <../base/Condition.h>

#include <stdio.h>

using namespace muduo;

struct msg
{
    struct msg* next;
    int num;
};

struct msg *head;

MutexLock mutex;
Condition con(mutex);

void consumer()  //消费者
{
    struct msg *mp;
    for(;;)
    {
        {
            MutexLockGuard lock(mutex);
            while(head == NULL) 
                con.wait();
            mp = head;
            head = mp->next;
        }
        printf("Consume %d\n", mp->num);
        free(mp);
        sleep(rand()%5);
    }     
}

void product()  //生产者
{
    struct msg* mp;
    for(;;)
    {
        mp = static_cast<*msg>(malloc(sizeof(struct msg)));
        mp->num = rand()%1000+1;
        printf("produce %d\n",mp->num);
        {
            MutexLockGuard lock(mutex);
            mp->next = head;
            head = mp;
        }
        con.notify();
        sleep(rand()%5);
    }
}


int main(int argc, char *argv)
{
    Thread t1(boost::bind(produce), "produce");
    Thread t2(boost::bind(consumer), "consumer");
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    return 0;
}
