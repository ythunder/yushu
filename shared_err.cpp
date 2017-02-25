/*************************************************************************
	> File Name: shared_err.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月13日 星期一 15时48分03秒
 ************************************************************************/

#include<iostream>
#include<memory>

using namespace std;


class B;
class A 
{
public:
    shared_ptr<B> pb_;
    ~A() { cout << "A delete\n"; }
};

class B 
{
public:
    shared_ptr<A> pa_;
    ~B() { cout << "B delete\n"; }
};

int main()
{
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());

    pb->pa_ = pa;
    pa->pb_ = pb;

    delete pb;

    cout << pb.use_count() << endl;
    cout << pa.use_count() << endl;

    return 0;
}
