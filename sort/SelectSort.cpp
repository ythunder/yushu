/*************************************************************************
	> File Name: SelectSort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月01日 星期二 20时23分40秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}


void SelectSort(int arr[], int num)
{
    int i, j, Mindex;
    for(i=0; i<num; i++)
    {
        Mindex = i;
        for(j=i+1; j<num; j++)
         {
            if(arr[j] < arr[Mindex])
                Mindex = j;
        }
    swap(&arr[i], &arr[Mindex]);
    }
}


int main(int argc, char *argv[])
{
    int arr[5] = {4,62,6,1,8};
    SelectSort(arr, 5);
    for(auto &i:arr)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
