#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M;
struct Node{
  int u,v,w;
};
Node node[200010];
int p[5010],ran[5010];
set<int> s;

bool comparison(Node n1, Node n2)
{
  return n1.w<n2.w;
}

void link(int p1, int p2)
{
  if(ran[p1]>ran[p2]) p[p2]=p1;
  else {p[p1]=p2;
  if(ran[p1]==ran[p2])
  ran[p2]++;}
}

int find(int k)
{
  if(k!=p[k]) p[k]=find(p[k]);
  return p[k];
}

int main()
{
  cin >> N >> M;
  For(1,N+1) p[i]=i;
  memset(ran,0,sizeof(ran));
  For(1,N+1) s.insert(i);
  For(0,M) cin >> node[i].u >> node[i].v >> node[i].w;
  sort(node,node+M,comparison);
  int u,v,sum=0,num=0;
  For(0,M)
  {
    u=node[i].u;v=node[i].v;
    if(find(u)!=find(v)) {link(find(u),find(v));sum+=node[i].w;num++;}
  }
  if(num==N-1) cout << sum << endl;
  else cout << "orz" << endl;
  return 0;
}
