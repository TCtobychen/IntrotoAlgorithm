//
//  DAG model.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/25.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;

int G[20][20];
int d[20];
int n,m;

int dp(int i)
{
    int &ans = d[i];
    if(ans > 0) return ans;
    ans = 1;
    for(int j=0;j<n;j++)
        if(G[j][i])
            ans = max(ans,dp(j)+1);
    return ans;
}

int main()
{
    cin >> n >> m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a>> b;
        G[a][b]=1;
    }
    int id=0,big=0;
    for(int i=0;i<n;i++)
        if(!d[i])
        {
            if(dp(i)>big) {big=dp(i);id=i;}
        }
    cout << id << ' ' << big << endl;
    return 0;
}
*/
