#include "tcpconnection.h"

TcpConnection::TcpConnection(EventLoop* loop,
                            int sockfd,
                            const InetAddress& localAddr,
                            const InetAddress& peerAddr)
    :loop_(loop),
    state_(kConnecting),
    sockfd_(nre Sockfd(sockfd)),
    channel_(new Channel(loop, sockfd)),
    localAddr_(localAddr),
    peerAddr_(peerAddr),
    highWaterMark_(64*1024*1024),
    reading_(true)
{
    channel_->setReadCallback(
        boost::bind(&TcpConnection::handleRead, this, _1));
    channel_->setWriteCallback(
        boost::bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(
        boost::bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(
        boost::bind(&TcpConnection::handleError, this));
}


TcpConnection::~TcpConnection()
{
    assert(state_ == kDisconnected);
}


void TcpConnection::send(const void* data, int len)
{
    if(state_ == kConnected)
    {
        if(loop_->isInLoopThread())
        {
            sendInLoop(message);
        
    }
}

void TcpConnection::send(Buffer* buf)
{
    if(state_ == kConnected)
    {
        sendInLoop(buf->ppeek(), buf->readableBytes());
        buf->retrieveAll();
    }
}



void TcpConnection::sendInLoop(const void* data, size_t len)
{
    ssize_t nwrote = 0;
    size_t remaining = len;
    bool faultError = false;
    
    /*判断连接是否关闭*/

    if(!channel_->isWriting() && outputBuffer_.readableBytes() == 0)
    {
        nwrote = sockets::write(channel_->fd(), data, len);
        if(nwrote >= 0)
        {
            remaining = len - nwrote;
            if(remaining == 0 && writeCompleteCallback_)
            {
                
            }
        }
    }

}
