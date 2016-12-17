/*************************************************************************
	> File Name: logFile.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 23时38分08秒
 ************************************************************************/

#include "logFile.h"
#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

using namespace netlib;

LogFile::LogFile(int rollSize)
    :rollSize_(rollSize),
    fillSize_(0),
    fileNumbers_(1)
    {
        fd_ = open("/home/yunting/note/mylog.log", O_WRONLY | O_APPEND | O_CREAT, S_IWUSR | S_IRUSR | S_IXUSR);
        if( fd_ <= 0 )
        {
            printf("%d\n", errno);
        }
        assert(fd_ > 0);
    }

LogFile::~LogFile()
{
    close(fd_);
}

void LogFile::append(char* log, int len)
{
    int ret = write(fd_, log, len);
    assert(ret == len);
    rollFile(ret);
}
    
void LogFile::rollFile(int curlen)
{
    fillSize_ += curlen;
    if(fillSize_ >= rollSize_)
    {
        printf("1G已满\n");
        fillSize_ = 0;
        char command[80];
        snprintf(command, sizeof(command), "mv /home/yunting/note/mylog.log /home/yunting/note/mylog%d.log", fileNumbers_);
        fileNumbers_++;
        system(command);
        fd_ = open("/home/yunting/note/mylog.log", O_WRONLY | O_APPEND | O_CREAT,S_IWUSR | S_IRUSR | S_IXUSR);
        assert(fd_ > 0);
    }
}


