#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
#define INF 1e9
using namespace std;

int N,M,head[10010],vis[10010],d[10010],cnt=0,ok=1;
struct Edge{int u,v,w,next;Edge(){}Edge(int u1,int v1,int w1,int next1){u=u1,v=v1,w=w1,next=next1;}}e[20010];

void add(int u, int v, int w){
  e[cnt]=Edge(u,v,w,head[u]);
  head[u]=cnt++;
}

int spfa(int n){
  if(d[n]==INF) d[n]=0;vis[n]=1;
  int v;
  for(int i=head[n];i!=-1;i=e[i].next){
    v=e[i].v;
    if(d[n]+e[i].w<d[v]){
      if(vis[v]) ok=0;
      else {
        vis[v]=1;d[v]=d[n]+e[i].w;
        spfa(v);vis[v]=0;
      }
    }
  }
  vis[n]=0;
}

int main(){
  memset(head,-1,sizeof(head));
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M){
    int k,a,b,c;cin >> k >> a >> b;
    if(k==1) {cin >> c;add(b,a,-c);}
    if(k==2) {cin >> c;add(a,b,c);}
    if(k==3) {add(a,b,0);add(b,a,0);}
  }
  cin.close();
  memset(vis,0,sizeof(vis));
  For(1,N+1) d[i]=INF;
  for(int i=1;i<N+1 && ok==1;i++) if(!vis[i]) spfa(i);
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
