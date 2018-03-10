#include<cstdio>
#include<string>
using namespace std;
const int maxn=10005,maxl=1000005;
int n,r,a[maxn],top,ans[maxl],vis[maxl];//记录ans数组，防止多次check同一个值,增大时间复杂度
int check(int x){
    if (ans[x]!=0) return ans[x];
    int sum=0; int y=x;
    while (y<=r) {sum+=vis[y]; y+=x;}
    ans[x]=sum;
    return sum;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;//vis[i]记录值为i的数有几个
        if (a[i]>r) r=a[i];
    }
    int top=r;
    for (int i=1;i<=n;i++) {
        while (top>1&&check(top)<i) top--;//top向下枚举，类似于单调栈的操作
        printf("%d\n",top);
    }
    return 0;
}
