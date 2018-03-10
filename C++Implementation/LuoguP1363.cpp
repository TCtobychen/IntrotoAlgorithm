#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#define pair<int, int> pr
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int M,N,ok;
queue<pr > q;
int vis[1510][1510];
int a[1510][1510];

void bfs(pr p)
{
  int x=p.first,y=p.second;
  if(x>0 && a[x-1][y])
  {
    if(vis[x-1][y]) {ok=1;return ;}
    else {vis[x-1][y]=1;pr p1(x-1,y);q.push(p1);}
  }
  if(x<N && a[x+1][y])
  {
    if(vis[x+1][y]) {ok=1;return ;}
    else {vis[x+1][y]=1;pr p2(x-1,y);q.push(p2);}
  }
  if(y>0 && a[x][y-1])
  {
    if(vis[x][y-1])
  }
}

void judge()
{
  memset(a,0,sizeof(a));
  memset(vis,0,sizeof(vis));
  ok=0;
  char c;
  pr p0;
  For(0,M)
    for(int j=0;j<N;j++) {cin >> c;if(c=='S') p0.first=i,p0.second=j,a[i][j]=1; if(c=='.') a[i][j]=1;}
  while(!q.emtpy()) q.pop();
  q.push(p0);vis[p0.first][p0.second]=1;
  while(!q.empty() && !ok)
  {
    pr tp=q.front();
    bfs(tp);
    q.pop();
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  while(cin >> M) {cin >> N;judge();}
  return 0;
}
