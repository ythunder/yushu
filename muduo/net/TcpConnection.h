/*************************************************************************
	> File Name: TcpConnection.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月02日 星期三 12时30分16秒
 ************************************************************************/

#ifndef _TCPCONNECTION_H
#define _TCPCONNECTION_H

#include <muduo/base/StringPrice.h>
#include <muduo/base/Types.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/InetAddress.h>

#include <boost/any.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

struct tcp_info;

namespace muduo
{
namespace net
{

class Channel;
class EventLoop;
class Socket;

class TcpConnection : boost::noncopyable,
public boost::enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(EventLoop* loop,
                 const string& name,
                 int sockfd,
                 const InetAddress& localAddr,
                 const InetAddress& peerAddr);
    ~TcpConnection();
    
    EventLoop* getLoop() const { return loop_; }
    const string& name() const { return name_; }
    const InetAddress& localAddress() const { return localAddr_; }
    const InetAddress& peerAddress() const { return peerAddr_; }
    bool connected() const { return state_ == kConnected; }
    bool disconnected() const { return state_ == kdisconnected; }

    bool getTcpInfo(struct tcp_info*) const;
    string getTcpInfoString() const;

    void send(const void* message, int len);
    void send(const StringPiece& message);
    void send(Buffer* message);
    void shutdown();

    void forceClose();
    void forceCloseWithDelay( double seconds );
    void setTcpNoDelay(bool on);
    void startRead();
    void stopRead();
    bool isReading() const { return reading_; }

    void setContext( const boost::any& context ) 
    { context_ = context; }

    const boost::any& getContext() const
    { return &context_; }

    void setConnectionCallback( const ConnectionCallback& cb )
    { connectionCallback_ = cb; }

    void setMessageCallback( const MessageCallback& cb )
    { messageCallback_ = cb; }

    void setWriteCompleteCallback(const MessageCallback& cb)
    { writeCOmpleteCallback_ = cb; }

    void setHighWaterMarkCallback( const HighWaterMarkCallback& cb, size_t highWaterMark )
    { highWaterMarkCallback_ = cb;  highWaterMark_ = highWaterMark; }

    void setCloseCallback( const CloseCallback& cb )
    { closeCallback_ = cb; }
    

    Buffer* inputBuffer() 
    { return &inputBuffer_; }

    Buffer* outputBuffer()
    { return &outputBuffer_; }

    void connectEstablished();

    void connectDestroyed();


private:
    /*建立连接后的连接状态*/
    enum StateE { kDisconnected, kConnecting, kConnected, kDisconnecting };

    void handleRead(Timestamp receiveTime);
    void handleWrite();
    void handleClose();
    void handleError();

    void sendInLoop(const StringPiece& message);
    void sendInLoop(const void* message, size_t len);

    void shutdownInLoop();

    void forceCloseInLoop();
    void setState(StateE s)  { state_ = s; }
    const char* stateToString() const;
    void startReadInLoop();
    void stopReadInLoop();

private:
    EventLoop* loop_;   
    const string name_;
    StateE state_;
    boost::scoped_ptr<Socket> socket_;
    boost::scoped_ptr<Channel> channel_;
    const InetAddress localAddr_;    
    const InetAddress peerAddr_;   //远程端的信息
    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;  //消息到达时怎么处理消息
    WriteCompleteCallback writeCompleteCallback_;   //低水位回调
    HighWaterMarkCallback highWaterMarkCallback_;  //高水位回调
    CloseCallback closeCallback_;
    size_t highWaterMark_;   //发送缓冲区数据的上限值
    Buffer inputBuffer_;   //输入Buffer
    Buffer outputBuffer_;
    boost::any context_;
    bool reading_;   //正在读数据
};

typedef boost::shared_ptr<TcpConnectiono> TcpConnectionPtr;

}
}

#endif
