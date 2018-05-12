#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,cnt=0,head[1010],vis[1010],dis[1010];
struct Edge{
  int u,v,next;
  Edge() {}
  Edge(int u1, int v1, int next1){u=u1,v=v1,next=next1;}
}e[1000010];

void add(int u, int v){
  e[cnt]=Edge(u,v,head[u]);
  head[u]=cnt++;
}

int bfs(int m){
  //cout << "Considering... " << m << endl;
  if(dis[m]>0) return dis[m];
  int temp=head[m];
  if(temp==-1) {dis[m]=1;return 1;}
  while(temp!=-1){
    //cout << "STUCK... " << temp <<  endl;
    int v=e[temp].v;temp=e[temp].next;
    //cout << "Now consider its child " << v << endl;
    dis[m]=max(dis[m],bfs(v)+1);
  }
  return dis[m];
}

int main(){
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  memset(head,-1,sizeof(head));
  cin >> N >> M;
  for(int l=0;l<M;l++){
    int num,start,temp,nex;
    vector<int> t1,t2;
    cin >> num >> start;temp=start;
    t1.push_back(start);
    For(0,num-1){
      cin >> nex;t1.push_back(nex);
      for(int j=temp+1;j<nex;j++) t2.push_back(j);
      temp=nex;
    }
    For(0,t1.size()) for(int j=0;j<t2.size();j++) add(t2[j],t1[i]);
  }
  cin.close();
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  int ans=0;
  For(1,N+1) ans=max(ans,bfs(i));
  cout << ans << endl;
  return 0;
}
