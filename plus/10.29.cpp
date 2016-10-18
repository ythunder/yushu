/*************************************************************************
	> File Name: 10.29.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月16日 星期二 01时48分44秒
    > Write a program using stream iterators to read a text file into a vector of strings.
 ************************************************************************/

#include <iostream>
#include <vector>
#include <istream>
#include <ostream>
#include <string>
#include <iterator>
#include <fstream>

using std :: vector;
using std :: string;
using std :: ifstream;
using std :: istream_iterator;
using std :: cout;

int main()
{
    ifstream ifs("file");
    istream_iterator<string> in(ifs), eof;
    vector<string> vec(in, eof);
    for (auto &i : vec) 
    {
        cout << i << " ";
    }
    return 0;
}

