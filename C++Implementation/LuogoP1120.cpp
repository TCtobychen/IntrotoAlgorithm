#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,num,target,maxn=0;
bool ok;
int a[70],vis[70],ind[60];

bool comparison(int a1, int a2)
{return a1>a2;}

void output()
{
  For(0,N) cout << vis[i] << ' ';
  cout << endl;
}

int aft(int last)
{
  int sum=0;
  For(last,N) if(!vis[i]) sum+=a[i];
  return sum;
}

inline void dfs(int last, int n)
{
  //output();cout << n << endl;
  if(num==0 && n==target) {ok=1;cout << target <<endl;return ;}
  if(aft(last)<n) return;
  if(n!=target){
    while(vis[last]) last++;
    int end=last+1;
    while(a[end]==a[last]) end++;
    int m=n/a[last];
    for(int i=min(end-last,m);i>=0;i--){
      //cout << i << endl;
      for(int j=0;j<i;j++) vis[last+j]=1;
      num-=i;if(n>i*a[last]) dfs(end,n-i*a[last]);
      else {dfs(1,target);if(!ok&&i==0) return;}
      num+=i;
      for(int j=0;j<i;j++) vis[last+j]=0;
      if(ok) return;
    }
  }
  else{
    while(vis[last]) last++;
    int end=last+1;
    while(a[end]==a[last]) end++;
    int m=target/a[last];
    for(int i=min(m,end-last);i>=1;i--){
      for(int j=0;j<i;j++) vis[last+j]=1;
      num-=i;if(n>i*a[last]) dfs(end,n-i*a[last]);
      else {dfs(1,target);if(!ok&&i==1) return;}
      num+=i;
      for(int j=0;j<i;j++) vis[last+j]=0;
      if(ok) return ;
  }
  }
}

int main()
{
  cin >> N;
  int t,cnt=0,sum=0;
  memset(vis,0,sizeof(vis));
  For(0,N) {cin >> t;if(t<=50) {a[cnt++]=t;maxn=max(maxn,t);sum+=t;}}
  //cout << sum << ' ' << maxn << endl;
  num=cnt;
  sort(a,a+N,comparison);
  //aft[N]=0;
  //for(int i=N-1;i>=0;i--) aft[i]=aft[i+1]+a[i];
  for(target=maxn;target<=sum && !ok;target++) if(sum%target==0) {
    //cout << target << endl;
    dfs(0,target);
  }
  return 0;
}

/*

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=70;
int n,a[N],cnt,maxn,maxnn;
bool cmp(int x,int y){return x>y;}
bool use[N];
inline void dfs(int ans,int sum,int goal,int now){
    if(sum*goal==maxn){printf("%d\n",goal); exit(0);}   //因为公因数是从小到大所以这里有答案直接退出
    if(maxn-ans<a[cnt])return;    //如果最小长度大于本组剩余长度return
    if(ans==goal){dfs(0,sum+1,goal,1); return;}    //满足长度 下一组 如果不行直接return
    for(register int i=now;i<=cnt;i++)
        if(!use[i] && ans+a[i]<=goal){
            use[i]=1;
            dfs(ans+a[i],sum,goal,i+1);
            use[i]=0;
            if(ans+a[i]==goal || ans==0)break;   //如果能组成一组却不可行或者有一组行不通直接退出
            while(a[i]==a[i+1])i++;
        }
}
int main(){
    scanf("%d",&n);
    for(register int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x<=50){a[++cnt]=x; maxn+=a[cnt]; maxnn=max(a[cnt],maxnn);}
    }
    sort(a+1,a+cnt+1,cmp);    //排序优化
    for(register int i=maxnn;i<=maxn/2;i++)  //最小的答案大于等于最大的一根，所以从最大的一根开始
        if(maxn%i==0)dfs(0,0,i,1);    //如果是总和的公因数 那么dfs
    printf("%d\n",maxn);
    return 0;
}

*/
