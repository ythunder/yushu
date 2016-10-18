/*************************************************************************
	> File Name: 9.18.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2016年01月31日 星期日 01时25分46秒
    > Write a program to read a sequece of strings from the standard input into a deque. Use iterator to write a loop to print the elements in the deque.
 ************************************************************************/

#include <iostream>
#include <deque>
#include <string>

using std :: deque;
using std :: string;
using std :: cout;
using std :: endl;
using std :: cin;

int main()
{
    deque<string> deq;
    string word;

    auto iter = deq.begin();

    while(cin >> word)
    {
        iter = deq.insert(iter, word);
    }
    for (auto& s : deq) {
        cout << s << endl;
    }
}
