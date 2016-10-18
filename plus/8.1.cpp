/*************************************************************************
	> File Name: 8.1.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月17日 星期日 21时31分45秒
 ************************************************************************/

#include <iostream>
using std :: istream;

istream& Read_data(istream& is)
{
    std :: string s;
    while (is >> s) {           
        std :: cout << s << std :: endl;
    }
    is.clear();     //复位
    return is;
}


int main()
{
    istream& s = Read_data(std::cin);
    int old_state = s.rdstate();　　　//记住s的当前状态
    std :: cout << old_state << std :: endl;
    return 0;
}

