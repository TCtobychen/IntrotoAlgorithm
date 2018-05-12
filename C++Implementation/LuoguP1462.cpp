#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
#define INF 1e9
using namespace std;

int N,M,cnt=0,head[10010],vis[10010],num=0;
long long int f[10010],B=0,d[10010];
struct Edge{int u,v,next;long long int w;
  Edge() {}
  Edge(int _u, int _v, long long int _w, int _next){
    u=_u, v=_v, next=_next, w=_w;
  }
}e[100010];

void add(int u, int v, long long int w){
  e[cnt]=Edge(u,v,w,head[u]);
  head[u]=cnt++;
  e[cnt]=Edge(v,u,w,head[v]);
  head[v]=cnt++;
}

/*bool spfa(int target){
  memset(vis,0,sizeof(vis));
  For(2,N+1) d[i]=INF;
  d[1]=
  queue<int> q;
  q.push(1);
  vis[1]=1;
  while(!q.empty()){
    int t=q.front();

  }
}*/

struct cmp1{
  bool operator() (int x,int y){
    return d[x]>d[y];
  }
};

void output(priority_queue<int, vector<int>, cmp1> q){
  cout << "OUTPUT" << endl;
  while(!q.empty()){
    cout << q.top() << ' ';
    q.pop();
  }
}

bool dij(int target){
  //cout << num++ << endl;
  priority_queue<int, vector<int>, cmp1> q;
  For(2,N+1) d[i]=INF;
  d[1]=0;
  q.push(1);
  while(q.top()!=N&&!q.empty())
  {
    int t=q.top();q.pop();
    int now=head[t];
    //cout << "WHAT" << t << endl;
    while(now!=-1){
      //cout << "HA" << endl;
      int v=e[now].v;
      long long int w=e[now].w;
      //cout << "considering..." << v << endl;
      //cout << f[v] << target <<' '<< d[v] << d[t]+w << endl;
      if(f[v]<=target&&d[v]>d[t]+w) {d[v]=d[t]+w;q.push(v);
        //cout << "Push" << v << endl;
      }
      now=e[now].next;
    }
  }
  //cout << d[N] << endl;
  if(d[N]<=B) return true;
  return false;
}

int bino(int start, int end){
  if(start>=end) {if(dij(start)) return start; else return 0;}
  int mid=(start+end)/2;
  if(dij(mid)) return bino(start,mid);
  else return bino(mid+1,end);
}

int main()
{
  memset(head,-1,sizeof(head));
  memset(f,0,sizeof(f));
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M >> B;int a,b;long long int w,maxn=0,minn=1e9;
  For(1,N+1) {cin >> f[i];maxn=max(maxn,f[i]);minn=min(minn,f[i]);}
  For(0,M) {cin >> a >> b >> w;add(a,b,w);}
  cin.close();
  int ans=bino(minn,maxn);
  if(ans>0) cout << ans << endl;
  else cout << "AFK" << endl;
  return 0;
}
