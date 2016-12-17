/*************************************************************************
	> File Name: tcpconnection.h
	> Author: 
	> Mail: 
	> Created Time: 2016年12月10日 星期六 19时43分21秒
 ************************************************************************/

#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H

struct tcp_info;

class TcpConnection
{
public:

    TcpConnection( EventLoop *loop,
                int sockfd,
                const InetAddress& localAddr,
                const InetAddress& peerAddr);

    ~TcpConnection();

    void send(const void* message, int len);
    void send(Buffer* message);

    void shutdown();
    void forceClose();

    void startRead();
    void stopRead();

    /*设置各种回调函数*/

    void connectEstablished();
    void connectDestroyed();



private:
    enum StateE{ kDisconnected, kConnecting, kConnected, kDisconnecting  };   //连接状态

    /*四个处理就绪事件函数*/
    void handleRead();
    void handleWrite();
    void handleClose();
    void handleError();

    /*发送消息*/
    void sendInLoop(const void* message, size_t len);
    
    /*关闭连接*/
    void shutdownInLoop();
    void forceCloseInLoop();

    /*开始读，停止读*/
    void startReadInLoop();
    void stopReadInLoop();

    /*所在loop线程*/
    EventLoop* loop;
    
    /*此连接的连接socket，和自己的事件分发器*/
    boost::scoped_ptr<Socket>  socket_;
    boost::socped_ptr<Channel> channel_;

    /*连接的本地地址和对端地址*/
    const InetAddress localAddr_;
    const InetAddress peerAddr_;

    /*连接的回调*/
    ConnectionCallback connectionCallback_;
    MessageCallback    messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;
    HighWaterMarkCallback highWaterMarkCallback_;
    CloseCallback      closeCallback_;

    /*水位，应用层buffer*/
    sizet_t highWaterMark_;
    Buffer inputBuffer_;
    Buffer outputBuffer_;

    boost::any context_;
    bool reading_;


};


#endif
