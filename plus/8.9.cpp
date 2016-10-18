/*************************************************************************
	> File Name: 8.1.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月17日 星期日 21时31分45秒
 ************************************************************************/

#include <iostream>
#include <sstream>

using std :: istream;
using std :: cout;
using std :: endl;

istream& Read_data(istream& is)
{
    std :: string s;
    while (is >> s) {           
        cout << s << endl;
    }
    is.clear();     //复位
    return is;
}


int main()
{
    std :: istringstream strm("aaaa");
    Read_data(strm);
    return 0;
}

