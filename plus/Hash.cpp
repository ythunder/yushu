/*************************************************************************
    > File Name: Hash.cpp
    > Author: yunting
    > Mail: 1368282581@qq.com
    > Created Time: 2015年12月16日 星期三 13时25分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

const int HASH_LEN = 50;
const int M = 47;
const int NAME_NO = 30;

struct Name{
    char py[20] ;
    int  k;
};

Name NameList[HASH_LEN];

struct HASH{
    char py[20];
    int k;
    int si;
};

HASH HashList[HASH_LEN];


void createdHashList()
{
    for(int i = 0; i < 47; i++)
    {
        strcpy(HashList[i].py ,  "");
        HashList[i].k = 0;
        HashList[i].si = 0;
    }
    for(int i = 0; i < 47; i++)
    {
        int sum = 0;
        int adr = (NameList[i].k) % M; //哈希函数
        int d = adr;
        if(HashList[adr].si == 0) //如果不冲突
        {
            HashList[adr].k = NameList[i].k;
            strcpy(HashList[adr].py , NameList[i].py);
            HashList[adr].si += 1;  //赋值1
        } else {
            do
            {
                d = (d + NameList[i].k % 10 + 1) % M; //伪，随机散列
                sum += 1;
            }while(HashList[d].k != 0);
           
            HashList[d].k = NameList[i].k;
            strcpy(HashList[d].py , NameList[i].py);
            HashList[d].si = sum + 1;
        }
       
    }
}

void findList()
{
    char name[20] = {0};
    int s0 = 0, r, sum = 1, adr, d;
    cout<<"Please input the name:";
    cin>>name;

    for(r = 0; r < 20; r++)
    {
        s0 += name[r];
    }

    adr = s0 % M;  //哈希函数
    d = adr;

//-----------三种情况-------------------------------------
    if(HashList[adr].k == s0)
    cout<<"\n"<<"Name:"<<HashList[d].py<<" key:"<<s0<<"find len:"<<1<<endl;

    else if(HashList[adr].k == 0)
    cout<<"No such name!"<<endl;

    else
    {
        while(1)
        {
            d = (d + s0 % 10 + 1) % M;
            sum += 1;
            if(HashList[d].k == 0)
            {
                cout<<"No such name!"<<endl;
                break;
            }
           
            if(HashList[d].k == s0)
            {
               cout<<"\n"<<"Name:"<<HashList[d].py<<" key:"<<s0<<"find len "<<sum<<endl;
                break;
            }
        }
    }
}


void display()
{
    int i;
    float average = 0;
    printf("\n\naddress\tkey\t\tfindlen\t\tH(key)\tName\n");

    for(int i = 0; i < 50; i++)
    {
        printf("%d ", i);
        printf("\t%d ", HashList[i].k);
        printf("\t\t%d ", HashList[i].si);
        printf("\t\t%d ", HashList[i].k % M);
        printf("\t%s ", HashList[i].py);
        printf("\n");
    }

    for(int i = 0; i < 50; i ++)
    {
        average += HashList[i].si;
        average /= NAME_NO;
    }
    //printf("\n\n average find len: asl(%d) = %f\n\n", NAME_NO,average);
}


int main()
{
    int ch1;

    for (int i = 0; i != 32; ++i) {
        cin >> NameList[i].py;
         int s0 = 0;
        char *f = NameList[i].py;
        for(int r = 0; *(f+r) != '\0'; r++)
        {
            s0 += *(f+r);
        }
        NameList[i].k = s0;
    }
     createdHashList();

    while(1)
    {
        printf(" creating  HashList and finding \n");
        printf(" 1:dispaly\n");
        printf(" 2:find\n");

        cin>>ch1;
        if(ch1 == 1)
        display();
       
        if(ch1 == 2)
        findList();

        else continue;
    }
    return 0;
}





