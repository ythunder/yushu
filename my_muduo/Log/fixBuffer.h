/*************************************************************************
	> File Name: fixBuffer.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 18时27分14秒
 ************************************************************************/

#ifndef _FIXBUFFER_H
#define _FIXBUFFER_H

#include <vector>
#include <string>
#include <assert.h>
#include <fcntl.h>

namespace netlib
{
    class FixBuffer
    {
    public:
        FixBuffer()
            :buffer_(1024*1024*4)
        {
            this->readableIndex_ = 0;
            this->writeableIndex_ = 0;
        }

        ~FixBuffer()
        {
        }

        int readableSize(void)   //可读字节数
        {
            return this->writeableIndex_ - readableIndex_;
        }

        int writeableSize(void)   //可写字节数
        {
            return buffer_.size() - this->writeableIndex_;
        }

        void append(const char *data, int len)    //缓冲区写入字符串
        {
            std::copy(data, data + len, getWritePeek());
            moveWriteIndex(len);
        }

        char *getReadPeek(void)   //获得读指针
        {
            return this->begin() + readableIndex_;
        }
        char *getWritePeek(void)  //获得写指针
        {
            return this->begin() + writeableIndex_;
        }
        void moveWriteIndex(int len)   //移动写指针
        {
            writeableIndex_+= len;
        }

        void resetBuffer(void)   //重置读写指针
        {
            readableIndex_ = 0;
            writeableIndex_ = 0;
        }
    
    private:
        char *begin()
        {
            return &*buffer_.begin();
        }
        std::vector<char> buffer_;
        int readableIndex_;
        int writeableIndex_;
    };
}
#endif
