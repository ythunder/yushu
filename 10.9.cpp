/*************************************************************************
	> File Name: 10.9.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年02月15日 星期一 11时25分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std :: vector;
using std :: string;
using std :: cout;
using std :: endl;
using std :: sort;
using std :: unique;

int main()
{
    vector<string> words = {"fox", "the", "jumps", "fox", "red", "blue", "jumps"};
       for (auto &i : words) 
    {
        cout << i << " ";
    }
    cout << endl;
    sort (words.begin(), words.end());
    for (auto &i : words) 
    {
        cout << i << " ";
    }
    cout << endl;
    
    auto end_unique = unique(words.begin(), words.end());
    for (auto &i : words) 
    {
        cout << i << " ";
    }
    cout << endl;

    words.erase(end_unique, words.end());
    for (auto &i : words)
    {
        cout << i << " ";
    }
    cout <<endl;
}

