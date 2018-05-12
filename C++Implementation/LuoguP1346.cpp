#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
#define INF 1e9
using namespace std;

int N,S,E,cnt=0,head[110],vis[110],d[110];
struct Edge{
  int u,v,w,next;
  Edge() {}
  Edge(int _u, int _v, int _w, int _next){
    u=_u, v=_v, w=_w, next=_next;
  }
}e[10010];

void add(int u, int v, int w){
  e[cnt]=Edge(u,v,w,head[u]);
  head[u]=cnt++;
}

void spfa(){
  For(1,N+1) d[i]=INF;
  d[S]=0;
  queue<int> q;
  q.push(S);
  vis[S]=1;
  while(!q.empty()){
    int t=q.front();q.pop();vis[t]=0;
    int now=head[t];
    while(now!=-1){
      int v=e[now].v, w=e[now].w;
      if(d[v]>d[t]+w) {d[v]=d[t]+w; if(!vis[v]) {q.push(v);vis[v]=1;}}
      now=e[now].next;
    }
  }
  if(d[E]==INF) cout << -1 << endl;
  else cout << d[E] << endl;
}

struct cmp1{
  bool operator() (int x, int y){
    return d[x]>d[y];
  }
};

void dij(){
  For(1,N+1) d[i]=INF;
  d[S]=0;
  priority_queue<int, vector<int>, cmp1> q;
  q.push(S);
  while(!q.empty()){
    int t=q.top();q.pop();
    int now=head[t];
    while(now!=-1){
      int v=e[now].v, w=e[now].w;
      if(d[v]>d[t]+w) {d[v]=d[t]+w;q.push(v);}
      now=e[now].next;
    }
  }
  if(d[E]==INF) cout << -1 << endl;
  else cout << d[E] << endl;
}

int main()
{
  memset(head,-1,sizeof(head));
  memset(vis,0,sizeof(vis));
  int num=0,temp;
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> S >> E;
  For(1,N+1) {cin >> num; if(num!=0){cin >> temp; add(i,temp,0); for(int j=1;j<num;j++) {cin >> temp;add(i,temp,1);}}}
  cin.close();
  //spfa();
  dij();
  return 0;
}
