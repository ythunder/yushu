/*************************************************************************
	> File Name: 9.13.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月30日 星期六 21时30分13秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>

using std :: vector;
using std :: list;
using std :: cout;
using std :: endl;

int main()
{
    list<int> lis(10, 2);
    vector<int> vec(10, 3);

    vector<double> dvec(lis.begin(), lis.end());
    for (auto &i : dvec) {
        cout << i;
    }
    cout << endl;

    vector<double> dve(vec.begin(), vec.end());
    for (auto &j : dve) {
        cout << j;
    }
    cout << endl;

    return 0;
}


