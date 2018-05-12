#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <fstream>
#include <vector>
#define For(x,y) for(int i=x;i<y;i++)
#define INF 1e9
using namespace std;

int N,M,C,A,B,d[100010],head[100010],vis[100010],cnt=0;
struct Edge{
  int u,v,w,next;
  Edge() {}
  Edge(int _u, int _v, int _w, int _next){
    u=_u, v=_v, w=_w, next=_next;
  }
}e[500010];

void add(int u, int v, int w){
  e[cnt]=Edge(u,v,w,head[u]);
  head[u]=cnt++;
}

void output(){
  For(1,N+1) cout << d[i] << ' ';
  cout << endl;
}

void spfa(){
  memset(vis,0,sizeof(vis));
  queue<int> q;
  For(1,N+1) d[i]=INF;
  d[A]=0;
  vis[A]=1;q.push(A);
  while(!q.empty()){
    int t=q.front();q.pop();vis[t]=0;
    //cout << "Considering..." << t << endl;
      For(1,N+1){
      if(d[i]>d[t]+(t^i)*C) {d[i]=d[t]+(t^i)*C;if(!vis[i]) {q.push(i);vis[i]=1;}}
    }
    int now=head[t];
    while(now!=-1){
      int v=e[now].v, w=e[now].w;
      if(d[v]>d[t]+w) {d[v]=d[t]+w;if(!vis[v]) {q.push(v);vis[v]=1;}}
      now=e[now].next;
    }
  }
  // output();
  cout << d[B] << endl;
}

struct cmp1{
  bool operator() (int x, int y){
    return d[x]>d[y];
  }
};

void dij(){
  priority_queue<int, vector<int> , cmp1> q;
  For(1,N+1) d[i]=INF;
  d[A]=0;
  q.push(A);
  while(q.top()!=B){
    int t=q.top();q.pop();
    //cout << t << endl;
    For(1,N+1){
      if(d[i]>d[t]+(t^i)*C && i!=t) {d[i]=d[t]+(t^i)*C;q.push(i);}
    }
    int now=head[t];
    while(now!=-1){
      int v=e[now].v, w=e[now].w;
      if(d[v]>d[t]+w) {d[v]=d[t]+w;q.push(v);}
      now=e[now].next;
    }
  }
  cout << d[B] << endl;
}

int main()
{
  int s,e,t;
  memset(head,-1,sizeof(head));
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M >> C;
  For(0,M) {cin >> s >> e >> t;add(s,e,t);}
  cin >> A >> B;
  cin.close();
  //spfa();
  dij();
  return 0;
}
