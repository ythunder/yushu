/*************************************************************************
	> File Name: lock.h
	> Author: 
	> Mail: 
	> Created Time: 2016年10月12日 星期三 23时20分31秒
 ************************************************************************/

#pragma once

#include <atomic>
#include <string>
#include <iostream>
#include <list>
#include <stdio.h>

template <typename T>

class LinkList
{
public:
    T data;
    LinkList<T> *next;
};

template  <typename T>
class LockFreeQueue
{
public:
    /*构造函数*/
    LockFreeQueue();

    /*入队*/
    void push_back(T t);

    /*出队*/
    T pop_front(void);

    /*判空*/
    bool isEmpty(void);

private:
    LinkList<T> *head_;
    LinkList<T> *tail_;
    std::atomic_int elementNumbers_;  //对int类型进行原子封装
};

template <typename T>
LockFreeQueue<T>::LockFreeQueue():head_(NULL),tail_(new LinkList<T>),elementNumbers_(0)
{
    head_ = tail_;
    tail_->next = NULL;
}

template <typename T>
void LockFreeQueue<T>::push_back(T t)
{
    auto newVal = new LinkList<T>;
    newVal->data = t;
    newVal->next = NULL;

    LinkList<T> *p;
    do
    {
        p = tail_;
    }while(!__sync_bool_compare_and_swap(&tail_->next,NULL,newVal));
    __sync_bool_compare_and_swap(&tail_,tail_,newVal);
    elementNumbers_++;
}

template <typename T>
T LockFreeQueue<T>::pop_front()
{
    LinkList<T> *p;
    do
    {
        p = head_->next;
        if(!p)
        {
            return -1;
        }
    }while(!__sync_bool_compare_and_swap(&head_->next,p,p->next));
    elementNumbers_--;
    return p->data;
}

template <typename T>
bool LockFreeQueue<T>::isEmpty()
{
    if(elementNumbers_== 0)
    {
        return true;
    } else {
        return false;
    }
}

