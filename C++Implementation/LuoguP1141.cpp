#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int N;
bool vis[1010][1010];
int a[1010][1010];
int poi[1010][1010];
int ans[100010];

queue<pair<int, int > > q;

void dojob(pair<int, int > pt, int n)
{
  int x=pt.first, y =pt.second;
  //cout << x << y << n << endl;
  //cout << vis[x+1][y] << vis[x][y]<<endl;
  if(x>0&&!vis[x-1][y]&&a[x-1][y]==!a[x][y])
    {vis[x-1][y]=1;pair<int, int> p1(x-1,y);q.push(p1);poi[x-1][y]=n;}
  if(x<N-1&&!vis[x+1][y]&&a[x+1][y]==!a[x][y])
    {vis[x+1][y]=1;pair<int, int> p2(x+1,y);q.push(p2);poi[x+1][y]=n;}
  if(y>0&&!vis[x][y-1]&&a[x][y-1]==!a[x][y])
    {vis[x][y-1]=1;pair<int, int> p3(x,y-1);q.push(p3);poi[x][y-1]=n;}
  if(y<N-1&&!vis[x][y+1]&&a[x][y+1]==!a[x][y])
    {vis[x][y+1]=1;pair<int, int> p4(x,y+1);q.push(p4);poi[x][y+1]=n;}
}

int calc(int x, int y, int n)
{
  if(poi[x][y]>0)
    return ans[poi[x][y]];
  int Ans=0;
  pair<int, int > p(x,y);
  vis[x][y]=1;
  poi[x][y]=n;
  q.push(p);
  while(!q.empty())
  {
    pair<int , int > pt=q.front();
    dojob(pt,n);
    q.pop();
    Ans++;
  }
  ans[n]=Ans;
  return Ans;
}

int main()
{
  int m,x,y;
  cin >> N >>m;
  For(0,N*N)
  scanf("%1d",&a[i/N][i%N]);
  memset(poi,0,sizeof(poi));
  memset(vis,0,sizeof(vis));
  For(0,m)
  {
    cin >> x >> y;
    cout <<calc(x-1,y-1,i+1) << endl;
  }
  return 0;
}
