//
//  poj1409.cpp
//  Learning C++
//
//  Created by TC on 2017/12/9.
//  Copyright © 2017年 杨. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

void judge(int * a, int n)
{
    int sum1=0,sum2=0;
    int k;
    for(k=2;k<=n;k++)
    {
        if(k*(k+1)/2==n)
            break;
    }
    for(int j=0;j<k;j++)
        sum1+=a[j];
    if(sum1!=a[n-1])
    {cout << "No solution" << endl;return;}
    int pro=1;
    for(int j=0;j<k;j++)
        pro*=a[j];
    cout << pro << endl;
    return ;
}

int main()
{
    int a[1000];
    int n;
    cin >> n;
    For(0,n)
        cin >> a[i];
    sort(a,a+n);
    judge(a,n);
}*/
