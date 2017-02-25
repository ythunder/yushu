/*************************************************************************
	> File Name: Link.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月17日 星期二 20时47分11秒
 ************************************************************************/


/*线性抽象类的定义*/
template<class dataType> 
class list {
public:
    virtual void empty() = 0;   //清空线性表
    virtual int getLength() = 0; //求得表的长度
    virtual void insert(int i,const dataType &x) = 0;   //插入操作
    virtual void remove(const dataType &x) = 0;    //删除操作
    virtual int search(const dataType &x) = 0;     //查找操作
    virtual dataType* visit(int i) = 0;             //访问表中第i个操作
    virtual void traval() = 0;                    //遍历线性表
};


