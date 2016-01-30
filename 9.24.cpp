/*************************************************************************
	> File Name: 9.24.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 02时10分51秒
    > Write a program that fetches the first element in a vector using at, the subscript operator, and begin. Test your program on an empty vector.
 ************************************************************************/

#include <iostream>
#include <vector>

using std :: vector;
using std :: cout;
using std :: endl;

int main()
{
    vector<int> vec;

    //cout << vec.at(0) << endl;
    //cout << vec[0] << endl;
    cout << vec.front() << endl;
    cout << *vec.begin() << endl;

    return 0;
}

