/*************************************************************************
	> File Name: test_malloc.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年02月24日 星期五 23时22分45秒
 ************************************************************************/

#include<iostream>


int main()
{
    char* p = new char[5]{'a','b','c','d'};
    std::cout << "p = "<< &p << std::endl;

    char *p1 = p-3;
    std::cout << "p1 = "<< &p1 << std::endl;
    std::cout << *p1 << std::endl;

    delete [] p;
    
}

