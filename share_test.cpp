/*************************************************************************
	> File Name: share_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月13日 星期一 15时19分41秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>

using namespace std;

class Test 
{
public:
    Test(string s) 
    {
        str = s;
        cout << "Test create\n";
    }

    ~Test() 
    {
        cout << "Test delete" << str << endl;
    }

    string& getStr()
    {
        return str;
    }

    void setStr(string s)
    {
        str = s;
    }

    void print()
    {
        cout << str << endl;
    }
private:
    string str;
};


int main()
{
    shared_ptr<Test> ptr1(new Test("123"));
    shared_ptr<Test> ptr2(new Test("456"));

    cout << ptr1->getStr() << endl;
    cout << ptr2.use_count() << endl;

    ptr1 = ptr2;

    ptr1 -> print();

    cout << ptr1.use_count() << endl;
    cout << ptr2.use_count() << endl;

    ptr1.reset();
    ptr2.reset();

    
    return 0;
}

