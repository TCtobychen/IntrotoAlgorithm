//
//  Linear time maximum subarray.cpp
//  Learning C++
//
//  Created by TC on 2017/9/18.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int l1=0,r1=0,l2=0,n;
int maxm1=0,maxmt=0;
int a[100];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        if(maxmt+a[i]>0)
            maxmt+=a[i];
        else {maxmt=0;l2=i+1;}
        if(maxmt>maxm1)
        {l1=l2;r1=i;maxm1=maxmt;}
    }
    if(maxm1>0){cout << l1 << ' '<<r1 << ' '<<maxm1 << endl;}
    else cout << "Nothing" << endl;
    return 0;
}*/
