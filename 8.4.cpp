/*************************************************************************
	> File Name: 8.4.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月18日 星期一 14时20分43秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std :: string;
using std :: ifstream;
using std :: cout;
using std :: endl;
using std :: vector;

void read_file (const string& filename, vector<string>& s) 
{
    int c = 0;
    ifstream in(filename);  //创建一个ifstream并打开文件filename
    /*
    if (in) {
        string buf;
       while ( std :: getline(in, buf))
        s.push_back(buf);
    }
    */
    while (in) {
        string buf;        
        if(std :: getline(in, buf)) { //从输入流读出数据写入buf
            s.push_back(buf);         //将buf内容压入s中

        }
    }
    
}

int main()
{
    vector<string> s;
    read_file("file", s);
    for (auto& str : s)　　　　//依次输出s中所存数据
    cout << str << endl;
    return 0;
}


