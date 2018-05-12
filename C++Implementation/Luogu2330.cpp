#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,cnt=0,ans=0,p[310],deg[310];
struct Edge{int u,v,w;Edge(){} Edge(int u1,int v1, int w1){u=u1,v=v1,w=w1;}}e[50010];

void add(int u, int v, int w){
  e[cnt++]=Edge(u,v,w);
}

bool comparison1(Edge e1, Edge e2){
  return e1.w<e2.w;
}

int find(int u){
  if(u!=p[u]) p[u]=find(p[u]);
  return p[u];
}

void join(int p1, int p2){
  if(deg[p1]>deg[p2]) {p[p2]=p1;return ;}
  if(deg[p2]>deg[p1]) {p[p1]=p2;return ;}
  p[p2]=p1;deg[p1]++;return;
}

int getnext(int k){
  k++;
  while(1){
    int u=e[k].u,v=e[k].v,w=e[k].w;
    if(find(u)!=find(v)) {join(find(u),find(v));ans=max(ans,w);return k;}
    k++;
  }
}

int main(){
  int u,v,w;
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) {cin >> u >> v >> w;add(u,v,w);}
  cin.close();
  For(1,N+1) p[i]=i;
  memset(deg,0,sizeof(deg));
  sort(e,e+cnt,comparison1);
  int next=-1;
  For(1,N) next=getnext(next);
  cout << N-1 <<' ' << ans << endl;
  return 0;
}
