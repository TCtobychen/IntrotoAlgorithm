//
//  WEEK 2.cpp
//  Learning C++
//
//  Created by TC on 2017/9/2.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;

int res[10000000];
int d[30];
int minm=1000000;

void putin(int a,int b) // put the smallest dividor into d[]
{
    if(b==1)
        for(int i=2;i<=a;i++)
            if(a%i==0) {putin(i,b);return;}
    for(int i=d[b-1];i<=a;i++)
        if(a%i==0) {putin(i,b);return;}
    
}

int sum(int c) // get the temporary result
{
    int t=1;
    for(int i=1;i<c;i++)
        t=t*((int)(d[i]/2)+1);
    t=t*res[d[c]];
    return t;
}

void dojob(int i,int j)
{
    putin(i,j);
    i=i/d[j];
    minm=min(minm,sum(j));
    if(i>1)
        dojob(i,j+1);
    
}

int main()
{
    memset(res,0,sizeof(res));
    res[1]=1;
    for(int i=2;i<10000000;i++)
    {
        dojob(i,1);
        res[i]=minm;
    }
    return 0;
}*/
