/*************************************************************************
	> File Name: duotai.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月13日 星期一 12时54分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Shape {
protected:
    int width, height;
public:
    Shape(int a=0, int b=0) {
        width = a;
        height = b;
    }

    virtual int area()
    {
        cout << "Parent class area:" << endl;
        return 0;
    }

};

class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) : Shape(a,b) {}
    
    int area() 
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};

class Triangle : public Shape {
public:
    Triangle(int a= 0, int b = 0) : Shape(a, b) {  } 
    
    int area() {
        cout << "Triangle class area:" << endl;
        return (width * height/2);
    }
};

int main()
{
    Shape *shape;
    Shape sha(1,1);
    Rectangle rec(10,7);
    Triangle tri(10,5);

    sha.area();

    //存储矩形地址
    shape = &rec;
    shape -> area();

    //存储三角形面积
    shape = &tri;
    shape -> area();

    return 0;
}
