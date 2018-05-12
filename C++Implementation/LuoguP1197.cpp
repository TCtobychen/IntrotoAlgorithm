#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <stack>
#include <set>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int p[400010],head[400010],deg[400010],exs[400010],N,M,cnt=0;
struct Edge{int u,v,next;Edge(){} Edge(int u1, int v1, int next1){u=u1,v=v1,next=next1;}}e[200010];
stack<int> s,ans;

void add(int u, int v){
  e[cnt]=Edge(u,v,head[u]);
  head[u]=cnt++;
  e[cnt]=Edge(v,u,head[v]);
  head[v]=cnt++;
}

int find(int n){
  if(n!=p[n]) p[n]=find(p[n]);
  return p[n];
}

void join(int p1, int p2){
  int r1=find(p1),r2=find(p2);
  if(deg[r1]<deg[r2]) p[r1]=r2;
  else{
    p[r2]=r1;if(deg[r1]==deg[r2]) deg[r1]++;
  }
}

void connect(int n){
  exs[n]=1;
  int temp,v;
  for(temp=head[n];temp!=-1;temp=e[temp].next){
    v=e[temp].v;
    if(exs[v]) {join(n,v); }
  }
}

int count(){
  set<int> t;
  For(0,N) if(t.count(find(i))==0) t.insert(find(i));
  return t.size();
}

void output(){
  For(0,N) cout << find(i) <<' ';cout << endl;
}

int main(){
  memset(head,-1,sizeof(head));
  memset(deg,0,sizeof(deg));
  int u,v,k;
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) {cin >> u >> v;add(u,v);}
  For(0,N) exs[i]=1,p[i]=i;
  cin >> k;
  For(0,k) {int t;cin >> t;s.push(t);exs[t]=0;}
  cin.close();
  For(0,N) if(exs[i]) connect(i);
  while(!s.empty()){
    ans.push(count()-s.size());
    int t=s.top();s.pop();
    connect(t);
    //output();
  }
  ans.push(count());
  while(!ans.empty()) {cout << ans.top() << endl;ans.pop();}
  return 0;
}
