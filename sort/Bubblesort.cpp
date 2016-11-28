/*************************************************************************
	> File Name: Bubblesort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年11月01日 星期二 12时41分21秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>

void swap1(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}



void BubbleSort1(int arr[], int num)
{
    int i,j;

    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<num-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap1(&arr[j], &arr[j+1]);
        }
    }
}


void BubbleSort2(int arr[], int num)
{
    bool flag = true;
    int i,j;
    while(flag)
    {
        flag = false;
        for(int i=0; i<num-1; i++)
        {
            for(int j=0; j<num-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap1(&arr[j], &arr[j+1]);
                    flag = true;
                }
            }
        }
    }
}


void BubbleSort3(int arr[], int num)
{ 
    int flag = num-1;
    for(int i=0; i<num-1; i++)
    {
        int k = flag;
        for(int j=0; j<k; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap1(&arr[j], &arr[j+1]);
                flag = j;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    int a[5] = {4,2,1,5,9};
  BubbleSort1(a,5);
 //   BubbleSort2(a,5);
   // BubbleSort3(a,5);
    for(auto &t : a)
    std::cout << t << " " << std::endl;
    return 0;
}
