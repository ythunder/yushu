/*************************************************************************
	> File Name: asynLog.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 22时55分46秒
 ************************************************************************/

#ifndef _ASYNLOG_H
#define _ASYNLOG_H

#include <memory>
#include "fixBuffer.h"
#include "timestamp.h"
#include <vector>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>

namespace netlib
{
    enum LogLevel
    {
        OFF,    //关闭所有日志记录
        FATAL,  //导致程序退出的错误
        ERROE,  //发生了错误但不影响系统运行
        WARN,   //会出现潜在的错误情形
        INFO,   //系统发生了那些事情
        DEBUG,  //调试程序有关的信息
        ALL,    //输出所有日志记录
    };

    class AsynLog
    {
    public:
        AsynLog(int rollSize);
        ~AsynLog();
        void append(char *logline, LogLevel level);  //添加日志行
        void setLevel(LogLevel loglevel);  //设置日志的水平
        void stop(void);   //关闭日志

    private:
        void threadFunc(void);       //线程函数
        bool aboveLevel(LogLevel level);   //判断当前日志等级是否超过预设标准
        void writeBuffer(const char* logline, int len);     //将日志内容写入Buffer
        std::string toStringForLevel(LogLevel loglevel);    //将对应的level转换为字符串


    private:
        int rollSize_;   //文件达到多大时回滚
        bool running_;   //开始标志
        std::unique_ptr<FixBuffer>  currentBuffer_;   //当前buffer
        std::unique_ptr<FixBuffer>  nextBuffer_;      //备用buffer
        std::vector<std::unique_ptr<FixBuffer> >  buffers_;  //buffer数组
        std::thread  acceptThread_;                 //后台接收线程
        std::mutex  mutex_;                    //互斥变量
        std::condition_variable_any  condition_;     //条件变量
        Timestamp  timestamp_;                      //时间戳
        LogLevel  currentLoglevel_;                        //当前日志等级
    };
}
#endif
