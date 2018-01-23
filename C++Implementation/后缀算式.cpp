//
//  后缀算式.cpp
//  Learning C++
//
//  Created by TC on 2017/12/9.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int k=0,j=0;
char s[200];
int a[100];
char o[100];

int cal(int p, int q, char c)
{
    if(c=='+') return p+q;
    if(c=='-') return p-q;
    if(c=='*') return p*q;
    if(c=='/') return p/q;
    if(c=='^') return (int)pow(p,q);
    return 0;
}

void output(){
    for(int i = 0;i<k;i++)
        cout << a[i];
    cout << endl;
}

int dojob()
{
    if(k==1)
        return a[0];
    //output();
    for(int i=0;i<k;i++)
    {
        if(a[i]==-10000)
        {
            //cout << "?????";
            int p=a[i-2],q=a[i-1];
            if(o[0]=='+') a[i-2]=(p+q);
            if(o[0]=='-') a[i-2]=p-q;
            if(o[0]=='*') a[i-2]=p*q;
            if(o[0]=='/') a[i-2]=(int)p/q;
            if(o[0]=='^') a[i-2]=(int)pow(p,q);
            for(int m=i-1;m<k-2;m++)
                a[m]=a[m+2];
            k-=2;
            for(int m=0;m<j-1;m++)
                o[m]=o[m+1];
            j--;
            //output();
            break;
        }
    }
    return dojob();
}

int main()
{
    gets(s);
    int n = strlen(s);
    for(int i=0;i<n;i+=2)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[k]=s[i]-'0';
            k++;
        }
        else
        {
            o[j]=s[i];
            j++;
            a[k]=-10000;
            k++;
        }
    }
    //output();
    cout << dojob() << endl;
    
}*/
