#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
#define INF 1e9;
using namespace std;

int T, C, S, E, cnt=0;
int t[5]={0,1,2,3,4};
int d[2510],head[2510];
struct cmp1{
  bool operator ()(int x, int y){
    return d[x]>d[y];
  }
};

struct Edge{
  int u,v,w,next;
  Edge() {}
  Edge(int _u, int _v, int _w, int _next){
    u=_u, v=_v, w=_w, next=_next;
  }
}e[16210];

void add(int u, int v, int w){
  e[cnt]=Edge(u,v,w,head[u]);
  head[u]=cnt++;
  e[cnt]=Edge(v,u,w,head[v]);
  head[v]=cnt++;
}

void Dijsktra(){
  priority_queue<int, vector<int>, cmp1> q;
  q.push(S);
  while(q.top()!=E){
    int t=q.top();q.pop();
    int now=head[t];
    while(now!=-1){
      int u=e[now].u, v=e[now].v, w=e[now].w;
      if(d[v]>d[u]+w) {d[v]=d[u]+w;q.push(v);}
      now=e[now].next;
    }
  }
  cout << d[E] << endl;
}

int main()
{
  memset(head,-1,sizeof(head));
  int u,v,w;
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >>T >>C >> S >>E;
  For(0,C) {cin >> u >> v >> w;add(u,v,w);}
  cin.close();
  For(1,T+1) d[i]=INF;
  d[S]=0;
  Dijsktra();
  return 0;
}
