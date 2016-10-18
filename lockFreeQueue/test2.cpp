/*************************************************************************
	> File Name: test2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月13日 星期四 21时11分13秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
#include <thread>
#include <unistd.h>
#include "lock.h"

LockFreeQueue<int> queue;

void func1(void)
{
    for(int i=0; i<100000; i++)
    {
        queue.push_back(i);
    }
}

void func2(void)
{
    for(int i=100000; i<200000; i++)
    {
        queue.push_back(i);
    }
}

void func3(void)
{
    for(int i=0; i<100004; i++)
    {
        std::cout <<queue.pop_front() << " ";
    }
}

int main(int argc, char **argv)
{
    std::thread t1(func1);
    std::thread t2(func2);
    
    std::thread t3(func3);
    std::thread t4(func3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
