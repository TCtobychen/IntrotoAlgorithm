//
//  Copying Books UVa 714.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/24.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;

int a[200];
int n,sum,k,b=0;

int is_ok(int ans)
{
    int tsum=0,t=0,i=0;
    while(i<n && t<k)
    {
        tsum+=a[i];
        if(tsum>ans)
        {
            t++;
            tsum=a[i];
        }
        i++;
    }
    if(t<k) return 1;
    return 0;
}

int main()
{
    cin >> n >>k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(b<a[i]) b=a[i];
        sum+=a[i];
    }
    int div[2];
    int c=(int)sum/k;
    div[0]=max(b,c);div[1]=sum;
    int ans=div[0];
    while(!(is_ok(ans)&&!is_ok(ans-1)))
    {
        div[is_ok(ans)]=ans;
        ans=(int)(ans+div[1-is_ok(ans)])/2;
    }
    cout << ans << endl;
    return 0;
}*/
