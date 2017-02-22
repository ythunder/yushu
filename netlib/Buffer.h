/*************************************************************************
	> File Name: Buffer.h
	> Author: 
	> Mail: 
	> Created Time: 2017年02月21日 星期二 16时05分23秒
 ************************************************************************/


#include <string>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/uio.h>

class Buffer
{
public:
    static const int initialSize = 1024;

    Buffer()
       :buffer_(initialSize),
        readIndex_(0),
        writeIndex_(0)
    {
        assert(buffer_.size() == initialSize);
        assert(readIndex_ == 0);
        assert(writeIndex_ == 0);
    }

    
    ~Buffer() {}

    //可读字节数
    int readableSize() {
        return writeIndex_ - readIndex_;
    }

    //可写字节数
    int writeableSize()
    {
        return buffer_.size() - writeIndex_;
    }

    //已读过得可回收的字节数
    int recyclableSize()
    {
        return readIndex_;
    }
    
    char* begin() 
    {
        return &*buffer_.begin();
    }


    //移动写指针，append后自动移动
    void moveWriteIndex(int len)
    {
        writeIndex_ += len;
    }

    //移动读指针，外部从buffer读完后由用户调用
    void moveReadIndex(int len)
    {
        readIndex_ += len;
    }

    //获得可读地址
    char* getReadPeek()
    {
        return begin() + readIndex_;
    }

    //获得可写地址
    char* getWritePeek()
    {
        return begin() + writeIndex_;
    }


    //追加数据
    void append(const char* data, int len)
    {
        if(len > writeableSize()) {
            //确保空间可写
            if(writeableSize() + recyclableSize() >= len) {
                std::copy(begin() + readIndex_, begin() + writeIndex_, begin());
            writeIndex_ = readableSize();
            readIndex_ = 0;
            }
            else {
                buffer_.resize(buffer_.size() + len);
            }            
        }
        std::copy(data, data+len, getWritePeek());   //将data数据写入
        moveWriteIndex(len);
    }


    //作为inputBuffer从套接字中读取数据到buffer
    int readFromFd(int fd) 
    {
        //buffer中空间足够，从fd中读数据写入buffer
        if(writeableSize() > 1024*10) {
            int count = ::read(fd, getWritePeek(), writeableSize());
            assert(count >= 0);

            writeIndex_ += count;
            return count;
        }
        //空间不够大，把多出来的写到栈里
        else 
        {
            char extrabuf[65536];
            struct iovec vec[2];

            int writeable = writeableSize();
            vec[0].iov_base = getWritePeek();
            vec[0].iov_len = writeableSize();
            vec[1].iov_base = extrabuf;
            vec[1].iov_len = sizeof(extrabuf);

            int count = readv(fd, vec, 2);

            assert(count >= 0);

            if(count <= writeableSize()) {
                writeIndex_ += count;
            }
            else 
            {
                writeIndex_ = buffer_.size();
                append(extrabuf, count - writeable);
            }
            return count;
        }
        return 0;
    }

    int writeToFd(int fd)
    {
        int count = write(fd, getReadPeek(), readableSize());
        moveReadIndex(count);
        return count;
    }

private:
    std::vector<char> buffer_;
    int readIndex_;
    int writeIndex_;
};

