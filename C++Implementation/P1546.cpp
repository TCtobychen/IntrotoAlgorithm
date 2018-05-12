#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,cnt=0,vis[110],ans=0,deg[110];
int p[110];
struct Edge{int u,v,w;Edge(){} Edge(int u1, int v1, int w1){u=u1,v=v1,w=w1;}}e[20010];

void add(int m, int n, int dis){
  e[cnt++]=Edge(m,n,dis);
}

bool comparison1(Edge e1, Edge e2){
  return e1.w<e2.w;
}

int find(int u){
  if(p[u]!=u) p[u]=find(p[u]);
  return p[u];
}

void join(int p1, int p2){
  if(deg[p1]>deg[p2]) {p[p2]=p1;return;}
  if(deg[p2]>deg[p1]) {p[p1]=p2;return;}
  if(deg[p1]==deg[p2]) {p[p2]=p1;deg[p1]++;return ;}
}

int getnext(int k){
  k++;
  while(1){
    int u=e[k].u, v=e[k].v;
    //cout << "Considering " << u << ' ' << v <<' ' << e[k].w << endl;
    if(find(u)!=find(v)) {join(find(u),find(v));ans+=e[k].w;
      //cout << "FIND " << u << ' ' << v <<' ' << e[k].w << endl;
      return k;}
    k++;
  }
}

int main(){
  int dis;
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N;
  For(1,N+1) for(int j=1;j<N+1;j++) {cin >> dis; if(dis!=0) add(i,j,dis);}
  cin.close();
  memset(vis,0,sizeof(vis));
  For(1,N+1) p[i]=i;
  memset(deg,0,sizeof(deg));
  sort(e,e+cnt,comparison1);
  //For(0,cnt) cout << e[i].u << e[i].v << ' ' << e[i].w << endl;
  int next=0;
  For(1,N) next=getnext(next);
  cout << ans << endl;
  return 0;
}
