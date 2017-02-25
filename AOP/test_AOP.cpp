#include "AOP.h"
#include <functional>
#include <iostream>

using namespace std;

struct AA
{
    void Before(int i)
    {
        cout << "Before from AA" << endl;
    }

    void After(int i)
    {
        cout << "After from AA" << endl;
    }
};


struct BB
{
    void Before(int i)
    {
        cout << "Before from BB" << endl;
    }

    void After(int i)
    {
        cout << "After from BB" << endl;
    }
};

void HT(int i)
{
    cout << "real HT function" << i << endl;
}


int main()
{
    std::function<void(int)> f = std::bind(&HT, std::placeholders::_1);
    Invoke<AA>(f,1);
    Invoke<AA,BB>(f,1);

}
