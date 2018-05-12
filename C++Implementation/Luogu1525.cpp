#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,cnt=0,p[40010],deg[40010];
struct Edge{int u,v,w;Edge(){} Edge(int u1, int v1, int w1){u=u1,v=v1,w=w1;}}e[100010];

bool comparison1(Edge e1, Edge e2){
  return e1.w>e2.w;
}

void add(int u,int v, int w){
  e[cnt++]=Edge(u,v,w);
}

int find(int k){
  if(k!=p[k]) p[k]=find(p[k]);
  return p[k];
}

void join(int p1, int p2){
  if(deg[p1]>deg[p2]) {p[p2]=p1;}
  if(deg[p1]>deg[p2]) {p[p2]=p1;}
  if(deg[p1]==deg[p2]) p[p2]=p1;deg[p1]++;
  return ;
}

bool test(int n){
  int u=e[n].u,v=e[n].v;
  if(find(u)==find(v)) return false;
  join(find(u),find(v+N));
  join(find(u+N),find(v));
  return true;
}

int main(){
  int u,v,w;
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) {cin >> u >> v >> w;add(u,v,w);}
  cin.close();
  sort(e,e+cnt,comparison1);
  For(1,2*N+1) p[i]=i;
  memset(deg,0,sizeof(deg));
  int num=0;
  for(num=0;num<cnt;num++) if(!test(num)) break;
  if(num==cnt) cout << 0 << endl;
  else cout << e[num].w << endl;
  return 0;
}
