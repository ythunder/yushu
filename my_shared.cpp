/*************************************************************************
	> File Name: my_shared.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月13日 星期一 16时35分27秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

template<typename T>
class smart_ptrs 
{
public:
    smart_ptrs(T*);
    smart_ptrs(smart_ptrs&);

    T* operator -> ();  
    T& operator * ();

    smart_ptrs& operator = (smart_ptrs&);

    ~smart_ptrs();

private:
    int *count;
    T *p;
};

//定义构造函数
template<typename T>
smart_ptrs<T>::smart_ptrs(T *sp):count(new int(1)), p(sp){
    cout << "创建一个对象" << *p << "  引用计数为：" << *count << endl;
}

//定义拷贝构造函数
template<typename T>
smart_ptrs<T>::smart_ptrs(smart_ptrs &sp):count(&(++*sp.count)),p(sp.p) {
    cout << "拷贝对象" << *sp.p << " 引用计数为" << *sp.count << endl;
}

template<typename T>
T* smart_ptrs<T>::operator->() {
    return p;
}

template<typename T>
T& smart_ptrs<T>::operator*() {
    return *p;
}

template<typename T> 
smart_ptrs<T>&smart_ptrs<T>::operator=(smart_ptrs& sp) {
    ++*sp.count;
    if(--*count == 0) {
        delete count;
        delete p;
    }
    this->p = sp.p;
    this->count = sp.count;

    cout << "赋值操作，" << *sp.p << " 的引用计数变成" << *sp.count << endl;
    return *this;
}


template<typename T>
smart_ptrs<T>::~smart_ptrs() {
    
    cout << "析构操作，" << *p << "引用计数为" << *count << endl;
    if(--*count == 0) {
        delete count;
        delete p;
    }
}

int main()
{
    smart_ptrs<string> ptr1(new string("abc"));
    smart_ptrs<string> ptr2(ptr1);
    smart_ptrs<string> ptr3(new string("aaa"));
    ptr3 = ptr2;
    return 0;
}
