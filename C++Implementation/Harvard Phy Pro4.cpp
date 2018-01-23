//
//  Harvard Phy Pro4.cpp
//  Learning C++
//
//  Created by 杨 on 2017/8/7.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
#include <time.h>
#define random(x) (rand()%x)
using namespace std;

int t1=(int)time(0);
int n,pos,times;
int id[10000],res[10000];

bool check(int *a, int t)
{
    for(int j=0;j<t;j++)
        if(!a[j]) return true;
    return false;
}

void push()
{
    times++;
    if(random(2)) {
        if(pos<n-1) pos++;
        else pos=0;
        id[pos]=1;return;
    }
    else{
        if(pos>0) pos--;
        else pos=n-1;
        id[pos]=1;return;
    }
}

int main()
{
    double ans;
    memset(res,0,sizeof(res));
    cin >> n;
    int i;
    for(i=0;i<10000;i++)
    {
        pos=0;
        srand(t1++);
        memset(id,0,sizeof(id));
        id[pos]=1;
        while(check(id,n))
            push();
        res[pos]+=1;
    }
    ans=times/i;
    cout << ans << endl;
    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}*/
