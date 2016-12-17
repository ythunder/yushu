/*************************************************************************
	> File Name: logFile.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 23时33分02秒
 ************************************************************************/

#ifndef _LOGFILE_H
#define _LOGFILE_H

namespace netlib
{
    class LogFile
    {
    public:
        LogFile(int rollSize);
        ~LogFile();
        void append(char *log, int len);   //往磁盘里添加消息
        void rollFile(int curLen);   //滚动文件

    private:
        int rollSize_;   //文件滚动大小
        int fd_;         
        int fillSize_;  //当前文件填充大小
        int fileNumbers_;  //已有文件数量
    };
}
#endif
