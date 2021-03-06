/*************************************************************************
	> File Name: screen.cpp
	> Author: yunting
	> Mail:1368282581@qq.com 
	> Created Time: 2015年12月14日 星期一 13时32分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Screen {
public:
    typedef string :: size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), 
    contents(ht * wd, c) { }
    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0,width = 0;
    string contents;
};

inline Screen& Screen :: move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}



