/*************************************************************************
	> File Name: 8.5.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月18日 星期一 17时31分21秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using std :: vector;
using std :: string;
using std :: ifstream;
using std :: cout;
using std :: endl;

void read_file (const string& filename, vector<string>& s) 
{
    ifstream in(filename);
    if (in) {
        string buf;
        while (in >> buf) {
            s.push_back(buf);
        }
    }
}

int main()
{
    vector<string> s;
    read_file ("file", s);
    for (auto&str : s) {
        cout << str << endl;
    }
    return 0;
}

