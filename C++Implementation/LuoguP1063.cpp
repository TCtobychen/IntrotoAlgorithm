#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int d[210][210];
int vis[210][210];
int a[210];
int N;

int dojob(int start, int end)
{
  if(vis[start][end])
    return d[start][end];
  int ANS=0;
  For(start,end)
  ANS=max(ANS,dojob(start,i)+dojob(i+1,end)+a[start]*a[i+1]*a[end+1]);
  d[start][end]=ANS;
  vis[start][end]=1;
  return ANS;
}

void clear()
{
  memset(d,0,sizeof(d));
  memset(vis,0,sizeof(vis));
  For(0,2*N)
  {vis[i][i]=1;d[i][i]=0;}
}

int main()
{
  memset(a,0,sizeof(a));
  cin >> N;
  For(0,N) {cin >> a[i];a[i+N]=a[i];}
  int ans=0;
  For(0,N) {clear();ans=max(ans,dojob(i,i+N-1));}
  cout << ans << endl;
  return 0;
}
