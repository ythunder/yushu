/*************************************************************************
	> File Name: Socket.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 19时04分42秒
 ************************************************************************/

#include "Socket.h"
#include <iostream>
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <string>
#include <sstream>



Socket::Socket(int sockfd)
    :sockfd_(sockfd)
{
    std::stringstream stream_socket;
    std::string socket_string;
    stream_socket << sockfd;
    stream_socket >> socket_string;
    
    std::string last_string = "创建监听socket，只有一个, socket = " + socket_string;

    std::cout << last_string << std::endl;
   setNonBlocking();
    setReusePort(true);
}

Socket::~Socket()
{}


int
Socket::setNonBlocking()
{
    int old_option = fcntl(sockfd_, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(sockfd_, F_SETFL, new_option);
    return old_option;
}

int
setNonBlock(int connfd)
{
    int old_option = fcntl(connfd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(connfd, F_SETFL, new_option);
    return old_option;
}

void 
Socket::bindAddress(std::string ip, int port)
{

    const char* cip = ip.c_str();
    struct sockaddr_in address;
    bzero( &address, sizeof(address) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, cip, &address.sin_addr );
    address.sin_port = htons( port);

    int ret = ::bind(sockfd_, (struct sockaddr*)&address, sizeof(address));
    if(ret < 0)
    {
        std::cout << errno;
    }
    assert( ret != -1 );
}

void 
Socket::listen()
{
    int ret = ::listen(sockfd_, 100);
    assert(ret != -1);
}


int 
Socket::accept(struct sockaddr_in* addr)
{
    socklen_t addrlen = static_cast<socklen_t>(sizeof *addr);
    int connfd = ::accept(sockfd_, (struct sockaddr*)&addr, &addrlen);
    setNonBlock(connfd);
    if(connfd < 0)
    {
        int saveErrno = errno;
    }
    return connfd;
}

int
Socket::connect(const struct sockaddr* addr)
{
    int ret = ::connect(sockfd_, addr, sizeof *addr);
    if(ret < 0)
    {
        int saveErrno = errno;
        std::cout << "connect errno----";
        switch(saveErrno)
        {
            case EISCONN: std::cout << "sockfd已连接\n";  break;
            case EINTR: std::cout << "系统调用连接到达前被信号中止\n"; break;
            case ENETUNREACH: std::cout << "网络不可达\n"; break;
            default: std::cout << "else errno\n"; break;
        }
    }
    return ret;
}


ssize_t
Socket::read(int connfd, void* buf, size_t count)
{
     ssize_t ret = ::read(connfd, buf, count);
    return ret;
}

ssize_t
Socket::write(const void* buf, size_t count)
{
    ssize_t ret =  ::write(sockfd_, buf, count);
    return ret;
}

void 
Socket::shutdownWrite()
{
    if(::shutdown(sockfd_, SHUT_WR) < 0)
    {
        std::cout << "shutdownWrite errno\n";
    }
}

void 
Socket::setTcpNoDelay(bool on)
{
    int optval = 0;
    if(on)  optval = 1;
    ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY, &optval, static_cast<socklen_t>(sizeof optval));

}

void 
Socket::setReusePort(bool on)
{
    int optval = 0;
    if(on) optval = 1;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT, &optval, static_cast<socklen_t>(sizeof optval));
}

void 
Socket::close()
{
    std::cout << "sockfd has been closed\n";
    ::close(sockfd_);
}


