//
//  WEEK 2 1.cpp
//  Learning C++
//
//  Created by TC on 2017/9/3.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int pid[10000000];

void find_prime()
{
    pid[1]=1;pid[2]=0;
    for(int i=2;i<10000000;i++)
        if(pid[i]==0)
            for(int j=2;j<10000000/i;j++)
                pid[i*j]=1;
}

int main()
{
    double res[1000000];
    for(long long int i=2;i<1000000;i++)
        res[i]=(double)(i/2+1)/i;
    for(long long int i=3;i<1000000;i++)
        for(long long int j=3;j<1000000/i;j++)
            if(res[i]*res[j]<res[i*j])
                res[i*j]=res[i]*res[j];
    for(long long int i=3;i<1000000;i++)
        if(res[i]<=0.01) {cout << i << endl; break;}
    cout << endl;
    return 0;
}*/
