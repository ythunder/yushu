/*************************************************************************
	> File Name: 10.6.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 01时28分23秒
    > Using fill_n, write a program to set a sequence of int_values to 0;  
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std :: vector;
using std :: cout;
using std :: endl;
using std :: fill_n;

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7};
    fill_n(vec.begin(), vec.size(), 0);
    for (auto &i : vec) 
    {
        cout << i << " " ;
    }
    cout << endl;
}

