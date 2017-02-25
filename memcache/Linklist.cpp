/*************************************************************************
	> File Name: list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月17日 星期二 20时54分49秒
 ************************************************************************/

#include "list.h"
#include "Linklist.h"
#include<iostream>

/*构造方法,定义头尾节点*/
template<class dataType>
Linklist<dataType>::Linklist() {
    head_ = new node();
    tail_ = new node();

    head_ -> prev_ = NULL;
    tail_ -> next_ = NULL;

    head_ -> next_ = tail_;
    tail_ -> prev_ = head_;

    length_ = 0;
}


template<class dataType>
Linklist<dataType>::~Linklist() {
    node* temp = head_;
    while( head_ -> next_ != tail_ ) {   //只要没删完
        pop_front();                     //就继续删
    }
    length_ = 0;
}


/* 判空*/
template<class dataType>
bool 
Linklist<dataType>::empty() {
    if(length_ != 0) {
        return false;
    }
    return true;
}

/*获取长度*/
template<class dataType>
int 
Linklist<dataType>::getLength() {
    return length_;
}


/* 插入 */
template<class dataType>
void 
Linklist<dataType>::push_front(const dataType &x) {
    
}

template<class dataType>
void 
Linklist<dataType>::insert(int i, dataType &x) {}

template<class dataType>
void 
Linklist<dataType>::push_back(const dataType &x) {}


/* 删除 */
template<class dataType>
void 
Linklist<dataType>::remove(const dataType &x) {}

template<class dataType>
dataType* 
Linklist<dataType>::pop_front() {}

template<class dataType>
dataType* 
Linklist<dataType>::pop_back() {}


/*查找*/
template<class dataType>
int 
Linklist<dataType>::search(const dataType &x) {}

/*查看*/
template<class dataType>
dataType* 
Linklist<dataType>::visit(int i) {}

/*遍历*/
template<class dataType>
void 
Linklist<dataType>::traval() {}

/*
private:
    struct node {
        dataType data_;   //节点中保存的数据
        node* prev_;      //节点前驱
        node* next_;      //节点后继
        node(dataType d)
            :data_(d),
            prev_(null),
            next_(null) {}   //构造函数
    };
    node* head_;     //表头
    node* tail_;     //表尾
    int   length_;   //表长
};
*/
