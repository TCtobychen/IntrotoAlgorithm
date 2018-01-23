//
//  Hell on the markets UVa 1614.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/25.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int x,id;
    node(int x=0,int id=0):x(x),id(id){}
}a[100];

int sum=0,n;
int ans[100];

bool cmp(node i,node j){return i.x<j.x;}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].x;
        sum+=a[i].x;
        a[i].id=i;
    }
    if(sum%2==1) {cout << "IMPOSSIBLE" << endl; return 0;}
    sum=sum/2;
    int s=0;
    sort(a, a+n, cmp);
    for(int i=n-1;i>=0;i--)
    {
        if((s+a[i].x)<=sum) {s+=a[i].x;ans[a[i].id]=1;}
        else {ans[a[i].id]=-1;}
    }
    for(int i=0;i<n;i++)
        cout << ans[i]<<' ';
    cout << endl;
    return 0;
}*/
