//
//  Just Finish it up UVa 11093.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/24.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int a[100],id[100];
int n;

void combine(int j)
{
    if(a[j]<0&&j>0)
    {
        a[j-1]+=a[j];
        a[j]=0;id[j]=1;
        combine(j-1);
    }
}

int main()
{
    memset(id,0,sizeof(id));
    cin >> n;
    int temp=n;
    int c,b;
    while(temp--)
    {
        cin >> b >> c;
        a[temp]=b-c;
    }

    for(int i=1;i<n;i++)
        if(a[i]<0){
            combine(i);
        }
    if(a[0]<0)
    {
        a[n-1]+=a[0];
        a[0]=0;id[0]=1;
        combine(n-1);
    }
    if(a[0]<0)
        cout << "IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<n;i++)
            if(id[i]==0)
            {cout << i << endl;break;}
    }
    return 0;
}*/
