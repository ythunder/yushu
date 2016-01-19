/*************************************************************************
	> File Name: 8.10.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月19日 星期二 21时37分23秒
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using std :: string;
using std :: ifstream;
using std :: istringstream;
using std :: cout;
using std :: endl;
using std :: vector;
using std :: cerr;


//同8.4中，将文件file内容读入vector<string> s
void read_file (const string& filename, vector<string>& s)
{
    ifstream in(filename);
    while (in) {
        string buf;
        if (std :: getline(in, buf)) {
            s.push_back(buf);
        }
    }
}


int main()
{
    vector<string> s;

    read_file("file", s);
    for (auto& buf : s) {
        istringstream strm(buf);  //定义一个string输入类型，将绑定到刚读入的行
        string word;　　　
        while(strm >> word) {
            cout << word << endl;
        }
    }
    return 0;
}

