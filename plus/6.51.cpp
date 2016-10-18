/*************************************************************************
	> File Name: 6.51.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月04日 星期五 20时55分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

void f ()
{
    cout << "void f ()" << endl;
}

void f (int)
{
    cout << "void f (int)" << endl;
}

void f (int, int)
{
    cout << "void f (int, int)" << endl;
}

void f (double, double = 3.14)
{
    cout << "void f (double, double)" << endl;
}

int main ()
{
 //   cout << "f (2.56, 42)" << endl;  //调用时f(int,int) 和f(double,dounle)效果一样，二义性，出错 
   // f (2.56, 42);
    cout << "f (42)" << endl;
    f (42);
    cout << "f (42, 0)" << endl;
    f (42, 0);
    cout << "f (2.56, 3.14)" << endl;
    f (2.56, 3.14);
    return 0;
}
