#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,T[200010],r[200010],d[200010],vis[200010];
int ans=200010;

void read(int &x){
  x=0;
  char ch=getchar();
  while(ch<'0'||ch>'9') ch=getchar();
  while('0'<=ch && ch <='9') {x=x*10+ch-'0';ch=getchar();}
  return ;
}

void rmove(int n){
  d[n]=1,r[T[n]]--;
  //cout <<n<< r[T[n]] << d[T[n]] << endl;
  if(r[T[n]]==0&&d[T[n]]==0) rmove(T[n]);
}

void dfs(int n){
  int s=1,nex=T[n];
  vis[n]=1;
  while(vis[nex]!=1) s++,vis[nex]=1,nex=T[nex];
  ans=min(ans,s);
}

int main()
{
  cin >> N;
  memset(r,0,sizeof(r));
  For(1,N+1) {read(T[i]);r[T[i]]++;}
  memset(d,-1,sizeof(d));
  memset(vis,0,sizeof(vis));
  memset(d,0,sizeof(d));
  For(1,N+1) if(r[i]==0 && d[i]==0) rmove(i);
  //For(1,N+1) cout <<r[i] <<' ';cout << endl;
  For(1,N+1) if(vis[i]==0&&d[i]==0) dfs(i);
  cout << ans << endl;
  return 0;
}
