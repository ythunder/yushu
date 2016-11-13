/*************************************************************************
	> File Name: Server.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月08日 星期二 22时19分05秒
 ************************************************************************/

#ifndef _SERVER_H
#define _SERVER_H

#include "callback.h"
#include <memory>
#include <string>
#include "base_loop.h"

namespace net
{
class Server
{
public:
    Server(std::string ip, int port, int loopNumber);
    ~Server();
    void start(void);   //开始运行server

    void setConnectionCallback(ConnectionCallback cb)
    {
        connectioncallback_ = cb;
    }

    void setMessageCallback(MessageCallback cb)
    {
        messagecallback_ = cb;
    }

    void setCloseCallback(CloseCallback cb)
    {
        closecallback_ = cb;
    }

    void setWriteCompleteCallback(WriteCompleteCallback cb)
    {
        writecompletecallback_ = cb;
    }

private:
    const string ipAddr_;     //ip
    int port_;               //port
    ConnectionCallback connectioncallback_;  //连接回调
    MessageCallback    messagecallback_;     //信息回调
    WriteCompleteCallback writecompletecallback_;  //写完成回调
    CloseCallback      closecallback_;       //关闭回调
    std::shared_ptr<BaseLoop>  baseLoopPtr_;  //保存baseLoop的智能指针
};
}
#endif
