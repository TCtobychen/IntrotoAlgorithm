//
//  CombineStones.cpp
//  Learning C++
//
//  Created by TC on 2017/12/15.
//  Copyright © 2017年 杨. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int up = 1000000;
int dp[100][100];
int a[100];
int ANS=0;
int sum[100];

int dojob(int i, int j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=up)
        return dp[i][j];
    for(int k=i;k<j;k++)
        dp[i][j]=min(dp[i][j],dojob(i,k)+dojob(k+1,j)+sum[j]-sum[i-1]);
    return dp[i][j];
}
int N=0;

void greedy(int *b, int n)
{
    if(n==2)
    {
        ANS+=(b[0]+b[1]);
        return ;
    }
    int * p;
    int t=0;
    p=(int*)malloc((n-1)*sizeof(int));
    int mn=1000000;
    for(int i=0;i<n-1;i++)
    {
        int temp=b[i]+b[i+1];
        //cout << i << ' ' << temp <<endl;
        if(temp<mn)
        {
            mn=temp;
            t=i;
        }
    }
    //cout << t << endl;
    for(int i=0;i<t;i++)
        p[i]=b[i];
    p[t]=b[t]+b[t+1];
    for(int i=t+1;i<n-1;i++)
        p[i]=b[i+1];
    ANS+=(b[t]+b[t+1]);
    for(int i=0;i<n-1;i++)
        //cout << p[i];
    cout << endl;
    if(n>2)
        greedy(p,n-1);
    return ;
}

int main()
{
    srand((unsigned)time(NULL));
    a[-1]=up;
    sum[-1]=0;
    //cin >> N;
    N=5;
    a[N]=up;
    int sum1=0;
    //for(int i=0;i<N;i++)
    //{cin >> a[i];sum1+=a[i];sum[i]=sum1;}
    for(int l=0;l<10;l++){
    for(int z=0;z<N;z++)
    {int o=rand();a[z]=o%30+1;sum1+=a[z];sum[z]=sum1;cout << a[z] << endl;}
        cout <<endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if (i==j)
                dp[i][j]=0;
            else
                dp[i][j]=up;
        }
    greedy(a,N);
    int B=dojob(0,N-1);
        cout <<"HERE!" << ANS << ' ' <<B << endl;
    if(ANS!=B)
    {
        cout <<"Find!!!" << endl;
        for(int x=0;x<N;x++)
        cout << a[x] << endl;
        break;}
    }//I forgot to clear ANS and dp every loop......
}
*/
