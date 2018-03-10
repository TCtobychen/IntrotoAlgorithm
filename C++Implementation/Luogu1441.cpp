#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int vis[25],a[25];
bool d[2010];
int N,M,maxn=0;

void output()
{
  For(0,N) cout << vis[i] <<' ';
  cout << endl;
}

void dp()
{
  //output();
  int ans=0;
  memset(d,0,sizeof(d));
  d[0]=true;
  int last=0;
  For(0,N) if(vis[i]){
    for(int j =last+a[i];j>=a[i];j--) d[j]=(d[j-a[i]] || d[j]);
    last+=a[i];
  }
  For(0,last+1) if(d[i]==true) ans++;
  maxn=max(maxn,ans-1);
}

void dfs(int cur, int now)
{
  if(now==M && cur==N) {dp();return ;}
  if((N-cur)>(M-now)) {vis[cur]=1;dfs(cur+1,now);}
  if(now<M) {vis[cur]=0;dfs(cur+1,now+1);}
}

int main()
{
  cin >> N >> M;
  //cout << "???";
  memset(a,0,sizeof(a));
  For(0,N) cin >> a[i];
  //cout << "???";
  memset(vis,0,sizeof(vis));
  //cout << "???";
  dfs(0,0);
  cout << maxn << endl;
}
