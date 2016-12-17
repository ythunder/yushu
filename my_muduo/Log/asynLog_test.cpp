/*************************************************************************
	> File Name: asynLog_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月21日 星期五 14时53分29秒
 ************************************************************************/

#include "asynLog.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <thread>

netlib::AsynLog log(1024*1024*1024);

void func(void)
{
    char s[100] = "hello\n";
    log.setLevel(netlib::LogLevel::ALL);
    while(true)
    {
        log.append(s, netlib::LogLevel::INFO);
    }
}

int main(int argc, char **argv)
{
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);
    std::thread t4(func);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}

