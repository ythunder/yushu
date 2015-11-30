/*************************************************************************
	> File Name: 6.33.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年11月30日 星期一 20时49分36秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void print_vec (const vector<int> &v, int i)
{
    if (i == v.size())  return ;
    cout << v[i++] << " ";
    print_vec(v, i);
}

int main()
{
    int i=0;
    vector<int> v{10,5,3,2,3,2,44,1};
    print_vec(v, i);
    return 0;
}
