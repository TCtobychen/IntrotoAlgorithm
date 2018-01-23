//
//  Race to 1  UVa 11762.cpp
//  Learning C++
//
//  Created by 杨 on 2017/7/29.
//  Copyright © 2017年 杨. All rights reserved.
//

/*#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 1000005;
int vis[N], num[N], prime[N], n;
double f[N];

void init() {
    int k = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));
    memset(num, 0, sizeof(num));
    for(int i = 2; i < N; i++) {
        num[i] = num[i - 1];
        if(!vis[i]) {
            num[i]++;
            prime[k++] = i;
            vis[i] = 1;
            for(int j = 2; i * j < N; j++) {
                vis[i * j] = 1;
            }
        }
    }
}
double dfs(int x) {
    if(vis[x])
        return f[x];
    vis[x] = 1;
    int s = 0;
    double p = 1.0 / num[x];
    double sum = 0;
    for(int i = 0; i < num[x]; i++) {
        if(x % prime[i] == 0) {
            sum += dfs(x / prime[i]);
            s++;
        }
    }
    return f[x] = (sum + num[x]) / s;
}
int main(){
    init();
    memset(vis, 0, sizeof(vis));
    vis[1] = 1, f[1] = 0;
    int t;
    int cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("Case %d: %.10lf\n",cas++, dfs(n));
    }
    return 0;
}*/
