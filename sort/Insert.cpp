/*************************************************************************
	> File Name: Insert.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月01日 星期二 19时40分44秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>

void InsertionSort(int arr[], int num)
{
    int temp, j;
    for(int i=1; i<num; i++)
    {
        temp = arr[i];
        for(j=i; j>0 && arr[j-1] > temp; j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}

int main(int argc, char *argv[])
{
    int arr[5] = {4,2,5,1,9}; 
    InsertionSort(arr, 5);
    for(auto &i : arr)
    std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}

