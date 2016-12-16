/*************************************************************************
	> File Name: Socket.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 18时32分47秒
 ************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H

#include <sys/types.h>

class Socket
{
public:
    Socket(int sockfd);

    ~Socket();

    int setNonBlocking();   //设置为非阻塞

    ssize_t read(int fd, void *buf, size_t count);   //读取套接字

    ssize_t write(const void* buf, size_t count);    //写入

    void bindAddress(char* ip, int port);   //绑定地址

    void listen();    //监听

    int accept(struct sockaddr_in* peeraddr);   //接受连接

    int connect(const struct sockaddr* addr);

    void shutdownWrite();             //关闭写

    void setTcpNoDelay(bool on);     //设置为非延迟

    void setReusePort(bool on);     //设置端口可重用

   // void setKeepAlive(bool on);    //保活量

    void close();                   //关闭套接字

int fd()
    {
        return sockfd_;
    }
private:

    int sockfd_;
};
#endif
