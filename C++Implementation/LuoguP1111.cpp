#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int p[1010],deg[1010],N,M,cnt=0;
struct Edge{int u,v,t;Edge(){} Edge(int u1,int v1,int t1){u=u1,v=v1,t=t1;}}e[100010];

bool comparison1(Edge e1, Edge e2){
  return e1.t<e2.t;
}

int find(int n){
  if(p[n]!=n) p[n]=find(p[n]);
  return p[n];
}

void join(int p1, int p2){
  int r1=find(p1),r2=find(p2);
  if(deg[r1]<deg[r2]) {p[r1]=r2;}
  else{
    p[r2]=r1;if(deg[r1]==deg[r2]) deg[r1]++;
  }
}

void connect(int k){
  join(e[k].u,e[k].v);
}

bool finish(){
  int pp=p[1];
  For(2,N+1) if(find(i)!=pp) return false;
  return true;
}

void output(){
  For(1,N+1) cout << p[i] <<' '; cout << endl;
}

int main(){
  int u,v,t,tm=0;
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) {cin >> u >> v >> t;e[cnt++]=Edge(u,v,t);}
  cin.close();
  For(1,N+1) p[i]=i;
  memset(deg,0,sizeof(deg));
  sort(e,e+cnt,comparison1);
  for(tm=0;tm<cnt && !finish();tm++) {connect(tm);
    //output();cout << tm << endl;
  }
  if(!finish()) {cout << -1 << endl;return 0;}
  if(tm==0) cout << 0 << endl;
  else cout << e[tm-1].t << endl;
  return 0;
}
