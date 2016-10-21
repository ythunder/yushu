/*************************************************************************
	> File Name: clock.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年10月19日 星期三 20时54分57秒
 ************************************************************************/

/*
*time.h中定义
*#define CLOCKS_PER_SEC ((clock_t)1000)
*/

#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void)
{
    long i=10000000L;
    clock_t start, finish;
    double duration;

    printf("time to do %ld empty loops is ", i);

    start = clock();    //返回"从开启这个进程"到”程序中调用clock函数“时之间的CPU时钟计时单元数

    while(i--) {  };
    
    finish = clock();

    duration = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("%f seconds \n", duration);

    return 0;
}

