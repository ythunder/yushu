/*************************************************************************
	> File Name: base_loop.h
	> Author: 
	> Mail: 
	> Created Time: 2016年11月09日 星期三 00时47分20秒
 ************************************************************************/

#ifndef _BASE_LOOP_H
#define _BASE_LOOP_H

namespace net

class BaseLoop
{
public:
    BaseLoop(int loopNumber);
    ~BaseLoop();
    int createListenfd(void);  //创建监听套接字

    int CreatedListenFd(void);   //创建监听套接字

    void start(void);          //开启

    void connectionHandle(int connfd);   //连接回调

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
    int listenfd_;     //监听套接字
    std::shared_ptr<LoopThreadPool> LoopThreadPoolPtr_;   //线程池对象指针

   ConnectionCallback connectioncallback__;
   MessageCallback messagecallback_;
   CloseCallback closecallback_;
   WriteCompleteCallback writecompletecallback_;
};
#endif
