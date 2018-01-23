//
//  poj1182.cpp
//  Learning C++
//
//  Created by TC on 2017/12/18.
//  Copyright © 2017年 杨. All rights reserved.
//
/*
#include <iostream>
using namespace std;
const int maxn = 1000;
int N,K;
int ANS=0;
int par[maxn]={0};
int rank1[maxn];

int Findset(int x)
{
    if(x==par[x])
        return x;
    return par[x]=Findset(par[x]);
}

int Makeset(int x)
{
    if(par[x])
    {cout << "The set of that element already exists" << endl;return 0;}
    rank1[x]=0;
    return par[x]=x;
}

int Linkset(int x, int y)
{
    if(rank1[x]>rank1[y])
        return par[y]=x;
    if(rank1[x]<rank1[y])
        return par[x]=y;
    par[y]=x;
    rank1[x]++;
    return rank1[x];
}

int Union(int x, int y)
{
    int rootx=Findset(x);
    int rooty=Findset(y);
    return Linkset(rootx,rooty);
}

int main()
{
    
}
*/
