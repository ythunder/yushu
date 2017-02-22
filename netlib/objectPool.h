/*************************************************************************
	> File Name: objectPool.h
	> Author: 
	> Mail: 
	> Created Time: 2017年02月21日 星期二 19时45分53秒
 ************************************************************************/


 #pragma once

 #include <list>
 #include <iostream>
 #include <memory>

template <typename T>
class ObjectPool 
{
public:
    template<typename ...Args>
    ObjectPool(int number, Args ...args)
        :number_(number)
    {
        initObjectPool(args...);
    }

    //获取对象
    T* getObject(void)
    {
        T* objectPtr = objectPool_.front();
        objectPool_.pop_front();
        return objectPtr;
    }

    //归还对象
    void giveBackObject(T *t)
    {
        objectPool_.push_front(t);
    }

    //销毁所有对象
    ~ObjectPool()
    {
        for(auto x : objectPool_) {
            delete x;
        }
    }

private:
    template <typename ...Args> 
    void initObjectPool(Args ...args)
    {
        for(int i=0; i<number_; ++i) {
            objectPool_.push_back(new T(args...));
        }
    }

    std::list<T *> objectPool_;
    int number_;
};
