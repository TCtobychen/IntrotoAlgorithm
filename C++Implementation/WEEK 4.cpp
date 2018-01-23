//
//  WEEK 4.cpp
//  Learning C++
//
//  Created by TC on 2017/9/22.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int a[10000001];
bool id[10000001];
int l1=1;
int t=0;

bool is_prime1(int i)
{
    int b= sqrt(i);t++;
    for(int j=2;j<=b;j++)
    {
        if(id[j])
        {
            t++;
            if(i%j==0)
                return false;
        }
    }
    return true;
}

bool is_prime2(int i)
{
    int b=sqrt(i);t++;
    for(int j=2;j<=b;j++)
    {t++;if(i%j==0) return false;}
    return true;
}

void bruteforce()
{
    id[2]=1;
    for(int i=3;i<=10000000;i++)
        if(is_prime1(i))
            id[i]=1;
}

bool findn(int n)
{
    for(int i=n+1;i<10000001;i++)
        if(!id[i]){l1=i;return true;}
    return false;
}

void shuffle()
{
    while(findn(l1)&&l1<5000000){t++;
        for(int i=2;i<10000001/l1;i++)
        {id[l1*i]=1;t++;}}
}

int main()
{
    for(int i=1;i<=10000000;i++)
        a[i]=i;
    memset(id, 0, sizeof(id));
    double duration;
    clock_t start, finish;
    start=clock();
    bruteforce();
    //shuffle();
    cout << t << endl;
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << endl;
}*/
