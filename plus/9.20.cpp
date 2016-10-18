/*************************************************************************
	> File Name: 9.20.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 01时37分53秒
    > Write a program to copy elements from a list<int> into two deques. The even-elements should go into one deque and the odd ones into the other.
 ************************************************************************/

#include <iostream>
#include <list>
#include <deque>

using std :: deque;
using std :: list;
using std :: cout;
using std :: cin;
using std :: endl;

int main()
{
    list<int> lis{1,2,3,4,5,6,7,8,9};
    deque<int> odd, even;

    for (auto &i : lis) 
    {
        ( (i%2==0) ? odd : even).push_back(i);
    }
    for (auto &i : odd) 
    {
        cout << i << "  ";
    }
    cout << endl;
    for (auto &i : even) 
    {
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}

