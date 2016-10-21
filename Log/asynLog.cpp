/*************************************************************************
	> File Name: asynLog.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 23时23分11秒
 ************************************************************************/

#include <iostream>
#include "asynLog.h"
#include "logFile.h"
#include "timestamp.h"
#include "fixBuffer.h"
#include <stdio.h>
#include <string.h>
#include <mutex>
#include <functional>
#include <pthread.h>

using namespace netlib;

AsynLog::AsynLog(int rollSize)
    :rollSize_(rollSize),
    running_(true),
    currentBuffer_(new FixBuffer()),
    nextBuffer_(new FixBuffer()),
    acceptThread_(std::bind(&AsynLog::threadFunc, this))
{
}

AsynLog::~AsynLog()
{
    stop();
}


/*将单行日志整理成行写入buffer*/
void 
AsynLog::append(char *logline, LogLevel level)
{
    if(aboveLevel(level))
    {
        std::lock_guard<std::mutex> guard(mutex_);
        std::string logtxt(logline);
        std::string time(timestamp_.toStringTime());
        char thread_id[30];
        snprintf(thread_id, sizeof(thread_id),"threadid[%lu]: ", pthread_self());
        std::string leve(toStringForLevel(level));
        time = time + thread_id + leve + logtxt;
        writeBuffer(time.c_str(), time.size());
    }
}


/*设置日志等级*/
void 
AsynLog::setLevel(LogLevel loglevel)
{
    this->currentLoglevel_ = loglevel;
}

/*关闭日志*/
void 
AsynLog::stop(void)
{
    if(running_)
    {
        running_ = false;
    }
    acceptThread_.join();   //等待后台进程退出
    printf("日志系统已关闭\n");
}

    
void 
AsynLog::threadFunc(void)
{
    //已有两个buffer为前端，此时再分配两个buffer和一个bufferwrite
    std::unique_ptr<FixBuffer> newBuffer1(new FixBuffer);
    std::unique_ptr<FixBuffer> newBuffer2(new FixBuffer);
    std::vector<std::unique_ptr<FixBuffer>> buffersToWrite;
    LogFile  output(rollSize_);
    buffersToWrite.reserve(16);

    //三秒定时唤醒
    
    while(running_)
    {
        std::lock_guard<std::mutex> guard(mutex_);
        if(buffers_.empty())
        {
            condition_.wait_for(mutex_,std::chrono::seconds(3));
        }

    //current放入buffers， new1上位
        buffers_.push_back(std::move(currentBuffer_));
        currentBuffer_ = std::move(newBuffer1);
        buffersToWrite.swap(buffers_);   
    //如果next也不为空，next下放到buffers，new2上位
    //buffers 与 bufferwrite 互换
        if(!nextBuffer_)
        {
            nextBuffer_ = std::move(newBuffer2);
        }
        for(int i=0; i<buffersToWrite.size(); i++)
        {
            output.append(buffersToWrite[i]->getReadPeek(), buffersToWrite[i]->readableSize());
        }

    //上次上位时谁被置空了将人家填满
        if(!newBuffer1)
        {
            assert(!buffersToWrite.empty());
            newBuffer1 = std::move(buffersToWrite[0]);
            newBuffer1->resetBuffer();   //重置指针
        }
        if(!newBuffer2)
        {
            assert(!buffersToWrite.empty());
            newBuffer2 = std::move(buffersToWrite[1]);
            newBuffer2->resetBuffer();
        }
        buffersToWrite.clear();
    }
}

/*判断当前日志等级是否超过预设标准*/
bool 
AsynLog::aboveLevel(LogLevel level)
{
    return level <= currentLoglevel_;
}


/*把日志内容写入buffer*/
void 
AsynLog::writeBuffer(const char* logline, int len)
{
    if(currentBuffer_->writeableSize() >= len)
    {
        currentBuffer_->append(logline, len);
    }
    else
    {
        buffers_.push_back(std::move(currentBuffer_));
        if(nextBuffer_)
        {
            currentBuffer_ = std::move(nextBuffer_);
        }
        else
        {
            currentBuffer_.reset(new FixBuffer());
        }
        currentBuffer_->append(logline, len);
        condition_.notify_one();
    }
}

/*将对应日志等级转换为字符串*/
std::string 
AsynLog::toStringForLevel(LogLevel loglevel)
{
    switch(loglevel)
    {
        case LogLevel::OFF:
            return std::string("OFF ");break;
        case LogLevel::FATAL:
            return std::string("FATAL ");break;
        case LogLevel::ERROE:
            return std::string("ERROE ");break;
        case LogLevel::WARN:
            return std::string("WARN ");break;
        case LogLevel::INFO:
            return std::string("INFO ");break;
        case LogLevel::DEBUG:
            return std::string("DEBUG ");break;
        case LogLevel::ALL:
            return std::string("ALL ");break;
        default:return std::string("UNKNOWN ");
    }
    return NULL;
}
