/*************************************************************************
	> File Name: timestamp.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 20时08分40秒
 ************************************************************************/

#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H

#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

namespace netlib
{
    class Timestamp
    {
    public:
        Timestamp() {}
        ~Timestamp() {}

        /*获得本地时间标准格式*/
        static struct tm now(void)
        {
            struct timeval tv;
            struct tm time;

            gettimeofday(&tv, NULL);   //获得日历时间
            localtime_r(&tv.tv_sec, &time); //转为本地时间
            time.tm_year += 1900;
            time.tm_mon += 1;
            return time;
        }

        /*获得当前日历时间*/
        static struct timeval getTime(void)
        {
            struct timeval tv;
            gettimeofday(&tv, NULL);
            return tv;
        }

        /*将当前时间格式化输出*/
        char* toStringTime(void)
        {
            struct tm time;
            bzero(str_,sizeof(str_));
            time = now();
            snprintf(str_, sizeof(str_),"%d-%d-%d %d:%d:%d",time.tm_year, time.tm_mon, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
            return str_;
        }

        /*获得两个时间的时间差*/
        static int getTimeDiff(timeval v1, timeval v2)
        {
            int t;
            t = v1.tv_sec*1000000 + v1.tv_usec - v2.tv_sec*1000000 - v2.tv_usec;
            t = abs(t);
            return t;
        }

    private:
        char str_[200];    
    };
}
    #endif
