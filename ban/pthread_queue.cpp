/*************************************************************************
	> File Name: pthread_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月11日 星期二 20时16分59秒
 ************************************************************************/

#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
using namespace std;
template<typename T>

class SyncQueue
{

public:
    SyncQueue(int maxsize):m_maxSize(maxsize),m_needStop(false){}
    void Put(const T&x)
    {
        Add(x);
    }
    void Put(T &&x)
    {
        Add(std::forward<T>(x));
    }

    //从队列取事件
    void Take(T &t)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker,[this]{return m_needStop || NotEmpty();});
        if(m_needStop)
        {
            return;
        }
        t = m_queue.front();
        m_queue.pop_front();
        m_notFull.notify_one();
    }

    //取一个线程
    void Take(std::list<T> &list)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notFull.wait(locker,[this]{return m_needStop || NotEmpty();});
        if(m_needStop)
        {
            return;
        }
        list = std::move(m_queue);
        m_notFull.notify_one();
    }

    void Stop()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        m_needStop = true;
        m_notFull.notify_one();
        m_notEmpty.notify_one();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> locket(m_mutex);
        return m_queue.empty();
    }

    bool full()
    {
        std::lock_guard<std::mutex> locket(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> locket(m_mutex);
        return m_queue.size();
    }

    int Count()
    {
        return m_queue.size();
    }

private:

    bool NotFull() const{
        bool full = m_queue.size() >= m_maxSize;
        if(full)
        {
            cout << "缓冲区满了，需要等待……"<< endl;
        }
        return full;
    }

    bool NotEmpty() const{
        bool empty = m_queue.empty();
        if(empty)
        {
            cout << "缓冲区空了，需要等待，异步线程ID：" << std::this_thread::get_id() << endl;
        }
        return !empty;
    }

    template<typename F>

    void Add(F &&x)
    {
        std::unique_lock<std::mutex>  locker(m_mutex);  //锁住当前线程
        m_notFull.wait(locker, [this]{return m_needStop||NotFull();});   //当前线程阻塞等待，第二个参数为true时解除阻塞
        if(m_needStop)
        {
            return ;
        }
        m_queue.push_back(std::forward<F>(x));   //条件满足，事件加入队列
        m_notEmpty.notify_one();   //唤醒等待进程
    }

private:
    std::list<T> m_queue;  
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;
    std::condition_variable m_notFull;
    int m_maxSize;
    bool m_needStop; 
};
