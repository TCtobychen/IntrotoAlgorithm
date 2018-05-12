#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

stack<int> s;
vector<int> v1;
vector<int> v2;
int N,M,ans=0,cnt=0,dfn[5010],low[5010],ind=0,head[5010],ins[5010],vis[5010];
struct Edge{int u,v,next;Edge(){} Edge(int u1, int v1, int next1){u=u1,v=v1,next=next1;}}e[100010];

void add(int u, int v){
  e[cnt]=Edge(u,v,head[u]);
  head[u]=cnt++;
}

void tarjan(int n){
  dfn[n]=low[n]=++ind;
  s.push(n);vis[n]=1;ins[n]=1;
  int temp,v;
  for(temp=head[n];temp!=-1;temp=e[temp].next){
    v=e[temp].v;
    if(!vis[v]) {tarjan(v);low[n]=min(low[n],low[v]);}
    else if(ins[v]) low[n]=min(low[n],dfn[v]);
  }
  if(dfn[n]==low[n]){
    int num=0;
    v1.clear();
    while(s.top()!=n){
      num++;ins[s.top()]=0;v1.push_back(s.top());s.pop();
    }
    s.pop();ins[n]=0;num++;v1.push_back(n);
    if(ans<num){
      v2.clear();
      For(0,v1.size()) v2.push_back(v1[i]);
      ans=num;
    }
  }
}

int main(){
  memset(head,-1,sizeof(head));
  memset(ins,0,sizeof(ins));
  int a,b,k;
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) {cin >> a >> b >> k;add(a,b); if(k==2) add(b,a);}
  cin.close();
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  For(1,N+1) if(!vis[i]) tarjan(i);
  cout << ans << endl;
  sort(v2.begin(),v2.begin()+v2.size());
  For(0,v2.size()) cout << v2[i] << ' '; cout << endl;
  return 0;
}
