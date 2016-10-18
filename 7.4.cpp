/*************************************************************************
	> File Name: 7.4.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月09日 星期三 14时17分43秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Person
{
public:
    void Name() const
    {
        return name;
    };

    void Address() const
    {
        return address;
    }
private:
    string name;
    string address;
        
};

istream &read(istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

ostream &print(istream &os,const Person &item)
{
    os << "name :" << item.name <<"\n"
    << "address :" << item.address << "\n";
    return os;
}

int main()
{
    
    return 0;
}
