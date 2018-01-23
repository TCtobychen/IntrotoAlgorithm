//
//  Plato's Blocks.cpp
//  Learning C++
//
//  Created by TC on 2017/11/26.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int a[1000];
int flag[1000];
int res[1000];
int c[1000];
int counts=0;
int t=-1;
int N,K;

int getin(){
    cin >> counts;
    for(int i=0;i<2*counts;i++)
        cin >> c[i];
    char sign;
    cin >> sign;
    if(sign=='=')
        return 1;
    if(sign=='<')
        return 0;
    return 2;
}

void mark1(){
    for(int i=0;i<2*counts;i++)
        flag[c[i]-1]=1;
}
void mark0(){
    for(int i=0;i<counts;i++){
        if(flag[c[i]-1]==2)
            flag[c[i]-1]=1;
        if(flag[c[i]-1]==-1)
            flag[c[i]-1]=0;
    }
    for(int i=counts;i<2*counts;i++){
        if(flag[c[i]-1]==0)
            flag[c[i]-1]=1;
        if(flag[c[i]-1]==-1)
            flag[c[i]-1]=2;
    }
}
void mark2(){
    for(int i=0;i<counts;i++){
        if(flag[c[i]-1]==0)
            flag[c[i]-1]=1;
        if(flag[c[i]-1]==-1)
            flag[c[i]-1]=2;
    }
    for(int i=counts;i<2*counts;i++){
        if(flag[c[i]-1]==2)
            flag[c[i]-1]=1;
        if(flag[c[i]-1]==-1)
            flag[c[i]-1]=0;
    }
}
int srch(int i){
    for(int j=0;j<2*counts;j++)
        if(c[j]==i)
            return 1;
    return 0;
}
void refine(){
    for(int i=0;i<N;i++){
        if(res[i]==1)
            if(!srch(i+1))
                res[i]=0;
    }
}
int check(){
    int temp=0;
    for(int i=0;i<N;i++){
        if(res[i]==1&&(flag[i]!=1)){
            if(temp!=0)
                return 0;
            if(temp==0)
                temp=i+1;
        }
    }
    if(temp)
        return temp;
    return 0;
}
int main()
{
    cin >> N >> K;
    memset(res,0,sizeof(res));
    memset(flag,-1,sizeof(flag));
    for(int i=0;i<N;i++)
        res[i]=1;
    for(int i=0;i<K;i++){
        t=getin();
        if(t==1)
            mark1();
        if(t==0) {mark0();refine();}
        if(t==2) {mark2();refine();}
    }
    int ans=check();
    cout << ans << endl;
}*/
