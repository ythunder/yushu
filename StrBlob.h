/*************************************************************************
	> File Name: Strblob.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月28日 星期日 13时12分14秒
 ************************************************************************/

#ifndef _STRBLOB_H
#define _STRBLOB_H

#include <iostream>
#include <memory>
using namespace std;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob(); 
    StrBlob(std::initializer_list<string> il);

    size_type size() const { return data->size(); }
    
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }

    std::string& front();
    std::string& back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    
    void check(size_type i, const std::string &msg) const;
}

//默认构造函数分配一个空的vector<string>初始化data
StrBlob::StrBlob():data( make_shared<vector<string>>() ) {  };

//接受参数il将其传递给对应的vector构造函数，此构造函数通过拷贝列表中的值来初始化vector的元素
StrBlob::StrBlob(std::initializer_list<string> il):data(make_shared<vector<string>>(il)) {  };

//检查给定的索引i是否合法，如果非法，抛出异常，msg描述错误内容
void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

//元素访问函数
std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
#endif
