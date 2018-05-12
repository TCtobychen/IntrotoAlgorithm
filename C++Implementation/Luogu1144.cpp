#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <fstream>
#include <vector>
#define For(x,y) for(int i=x;i<y;i++)
#define Mod 100003
#define INF 1e9
using namespace std;


// Fast read may be needed.


int ans[1000010],dist[1000010];
vector<int> v[1000010];
int N,M;

struct node {int u,dis;node(int u1, int dis1){u=u1,dis=dis1;}};

void read(int &t){
  char ch;
  int x=0;
  ch=getchar();
  while(ch<'0' || ch >'9') ch=getchar();
  while('0'<=ch && ch <='9') x=x*10+ch-'0';
  t=x;
  return ;
}

int print(int t){
  if(t<0) return (t+Mod);
  return t;
}

int main(){
  int v1,v2;
  //ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) {scanf("%d%d",&v1,&v2);v[v1].push_back(v2);v[v2].push_back(v1);}
  //cin.close();
  For(1,N+1) dist[i]=INF;
  memset(ans,0,sizeof(ans));
  dist[1]=0;
  ans[1]=1;
  queue<node> q;
  node n0=node(1,0);
  q.push(n0);
  while(!q.empty()){
    node t=q.front();q.pop();
    int u=t.u;
    //cout << "Now handling " << u << " and "<< dist[u] << endl;
    For(0,v[u].size()){
      int uu=v[u][i];
      //cout << uu << dist[uu] << " , " << u << dist[u] << endl;
      if(dist[uu]==dist[u]+1) ans[uu]+=ans[u];
      if(dist[uu]>dist[u]+1) {//cout << "Find" << uu << "AND " << dist[uu] << endl;
      dist[uu]=dist[u]+1;ans[uu]+=ans[u];ans[uu]%=Mod;q.push(node(uu,dist[uu]));}
    }
  }
  For(1,N+1) cout << print(ans[i]%Mod) << endl;
  return 0;
}
