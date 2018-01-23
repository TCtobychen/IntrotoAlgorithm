//
//  Header.h
//  Learning C++
//
//  Created by 杨 on 2017/7/30.
//  Copyright © 2017年 杨. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <cmath>
#include <map>
using namespace std;

//插入排序
void insertion_sort(int *a, int s, int e)
{
    for(int i=s+1;i<e;i++)
        for(int j=i-1;j>=s;j--)
        {
            if(a[i]>=a[j])
            {
                int t=a[i];
                for(int m=i;m>j+1;m--)
                    a[m]=a[m-1];
                a[j+1]=t;
                break;
            }
            else if(j==s){
                int t=a[i];
                for(int m=i;m>=s+1;m--)
                    a[m]=a[m-1];
                a[s]=t;
            }
        }
}

//输出数列
void output_array(int *a,int n)
{
    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
    cout << endl;
}


//欧几里得算法
int gcd(int a,int b)
{
    if(!a) return b;
    return gcd(b%a,a);
}

//扩展欧几里得算法
void gcd_ex(int a,int b,int &d,int &x,int &y)
{
    if(!b) {d=a;x=1;y=0;}
    else {gcd_ex(b,a%b,d,y,x);y=y-x*a/b;}
}

//对互质的(a,n)求逆元
int f_rev(int a,int n)
{
    if(n<=1 || a<=1 || gcd(a,n)>1) return -1;
    int ans=0,y,d;
    gcd_ex(a,n,d,ans,y);
    while(ans<0 || ans>n)
    {
        if(ans < 0) ans+=n;
        if(ans > n) ans-=n;
    }
    return ans;
}

//Shank's Baby step Giant step algorithm
int shank_s(int a,int b,int n)
{
    int m=sqrt(n)+1,temp=1;
    map<int,int> x;
    x[1]=0;
    for(int i=1;i<=m;i++)
    {
        temp*=a;temp=temp%n;
        if(!x.count(temp)) x[temp]=i;
    }
    int v=f_rev(temp, n);
    for(int i=0;i<m;i++)
    {
        if(x.count(b)) return i*m+x[b];
        b*=v;b=b%n;
    }
    return -1;
}

//Fibonacci array
void c_fibonacci(int *t, int a, int b,int n)
{
    t[0]=a;t[1]=b;
    for(int i=2;i<n;i++)
        t[i]=t[i-1]+t[i-2];
}

int sum_array(int *a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    return sum;
}

//找到数组中第一个为0的数的index
int fnz(int *a,int n)
{
    for(int i=0;i<n;i++)
        if(a[i]==0)
            return i;
    return n;
}
#endif /* Header_h */
