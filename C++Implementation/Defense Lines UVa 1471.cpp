//
//  Defense Lines UVa 1471.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/23.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int n;
int a[200000];
int  fi[200000];

void f_i()
{
    int R=0;
    for(int i=0;i<n;i++)
    {
        if(R<i) R=i;
        while(a[R+1]>a[R])
            R++;
        fi[i]=R-i;
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    f_i();
    for(int i=0;i<n;i++)
        cout << fi[i] << ' ';
    cout << endl;
    return 0;
}*/
