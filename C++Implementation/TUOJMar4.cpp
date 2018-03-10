#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define pr pair<int,int>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,a[20][20],lt[20][20],vis[20][20],num=0;
int s1[4]={1,0,-1,0},s2[4]={0,1,0,-1};
int ans[400];

void bfs(int x, int y)
{
  vis[x][y]=1,lt[x][y]=num;
  queue<pr> q;
  pr p0(x,y);
  q.push(p0);
  while(!q.empty())
  {
    pr pt=q.front();
    int x1=pt.first,y1=pt.second,x2,y2;
    For(0,4){
      x2=x1+s1[i],y2=y1+s2[i];
      if(0<=x2&&x2<N&&0<=y2&&y<M&&!vis[x2][y2]){
        vis[x2][y2]=1,lt[x2][y2]=num;
        pr p1(x2,y2);
        q.push(p1);
      }
    }
    q.pop();
  }
  num++;
}

int main()
{
  cin >> N >> M;
  For(0,N) for(int j=0;j<M;j++) cin >> a[i][j];
  memset(vis,0,sizeof(vis));
  memset(ans,0,sizeof(ans));
  For(0,N) for(int j=0;j<M;j++) if(!vis[i][j]) bfs(i,j);

}
