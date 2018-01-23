//
//  WEEK 3.cpp
//  Learning C++
//
//  Created by TC on 2017/9/14.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int t1,t2,maxm=0,n;
int a[1000];

void dojob(int b1, int b2, int* t)
{
    if(b1==(b2-1)) {if(t[b1]>maxm) {t1=b1;t2=b2;maxm=t[b1];}return ;}
    int mid=(b1+b2)/2;
    dojob(b1,mid,t);
    dojob(mid,b2,t);
    int sum1=0,sum2=0,sum3=0,sum4=0,t3=0,t4=0;
    for(int i=mid-1;i>=b1;i--)
    {
        if(sum2<sum1+t[i])
        {sum2=sum1+t[i];t3=i;}
        sum1+=t[i];
    }
    for(int i=mid;i<b2;i++)
    {
        if(sum4<sum3+t[i])
        {sum4=sum3+t[i];t4=i;}
        sum3+=t[i];
    }
    if(sum2+sum4 > maxm) {maxm=sum2+sum4;t1=t3,t4=t2;}
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    dojob(0,n,a);
    cout << maxm <<' '<< t1 <<' '<< t2 << endl;
    return 0;
}*/
