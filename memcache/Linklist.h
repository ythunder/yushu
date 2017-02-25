/*************************************************************************
	> File Name: list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月17日 星期二 20时54分49秒
 ************************************************************************/

#include "list.h"
#include<iostream>

template<class dataType>
class Linklist : public list<dataType> {
public:
    Linklist();
    ~Linklist();

    /* 判空*/
    bool empty();

    /*获取长度*/
    int getLength();

    /* 插入 */
    void push_front(const dataType &x);
    void insert(int i, dataType &x);
    void push_back(const dataType &x);

    /* 删除 */
    void remove(const dataType &x);
    dataType* pop_front();
    dataType* pop_back();

    /*查找*/
    int search(const dataType &x);

    /*查看*/
    dataType* visit(int i);

    /*遍历*/
    void traval();

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

