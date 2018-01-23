//
//  A Spy in the Metro UVa 1025.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/26.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;

int n,T;
int spd[20],arrive[200][20][2],d[200][20],vis[200][20];
int M1,M2,m=0;

int dp(int a, int b)
{
    if(vis[a][b]) return d[a][b];
    vis[a][b]=1;
    int &temp = d[a][b];
    temp=dp(a+1,b)+1;
    if(arrive[a][b][0] && b<n && a+spd[b]<=T) temp=min(temp,dp(a+spd[b],b+1));
    if(arrive[a][b][1] && b>1 && a+spd[b-1]<=T) temp=min(temp,dp(a+spd[b-1],b-1));
    //cout << temp << ' '<<a<<' '<<b<<' '<<spd[b]<<' '<< arrive[a][b][0] <<' '<< b << ' ' << a+spd[b] << ' '<<dp(a+spd[b],b+1)<<endl;
    return temp;
}

int main()
{
    memset(arrive,0,sizeof(arrive));
    int a;
    cin >> n >> T;
    for(int i=1;i<n;i++)
        cin >> spd[i];
    cin >> M1;
    for(int i=0;i<M1;i++)
    {
        cin >> a;
        arrive[a][1][0]=1;
        for(int j=1;j<n;j++)
        {a+=spd[j];arrive[a][j+1][0]=1;}
    }
    cin >> M2;
    for(int i=0;i<M2;i++)
    {
        cin >> a;
        arrive[a][n][1]=1;
        for(int j=n-1;j>0;j--)
        {a+=spd[j];arrive[a][j][1]=1;}
    }
    d[T][n]=0;vis[T][n]=1;
    for(int i=T+1;i<200;i++)
        for(int j=1;j<20;j++)
        {vis[i][j]=1;}
    int res = dp(0,1);
    cout << res << endl;
    return 0;
}*/
