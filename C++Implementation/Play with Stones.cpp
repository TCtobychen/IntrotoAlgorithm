//
//  Play with Stones.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/28.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <iostream>
using namespace std;

int main()
{
    int SG[100];
    int vis[200];
    SG[1]=0;
    for(int i=2;i<100;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j*2<=i;j++)
            vis[SG[i-j]]=1;
        for(int j=0;j<100;j++)
            if(!vis[j])
            {
                SG[i]=j;
                break;
            }
    }
    for(int i=1;i<50;i++)
        cout << SG[i*2-1] << endl;
    return 0;
}*/
