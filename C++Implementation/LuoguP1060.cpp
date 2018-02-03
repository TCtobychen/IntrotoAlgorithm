#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int d[30][30010];
int vis[30][30010];
int N,M;
int v[30],p[30];

int dojob(int n, int m)
{
  //cout << n << ' '<< m << endl;
  if(vis[n][m])
    return d[n][m];
  if(m>=v[n])
  d[n][m]=max(dojob(n-1,m),v[n]*p[n]+dojob(n-1,m-v[n]));
  else
  d[n][m]=dojob(n-1,m);
  vis[n][m]=1;
  return d[n][m];
}

void initial()
{
  memset(vis,0,sizeof(vis));
  For(0,N+1)
  {d[0][i]=0;vis[0][i]=1;}
  For(0,M+1)
  {d[i][0]=0;vis[i][0]=1;}
}

int main()
{
  cin >> N>> M;
  For(0,M)
  cin >> v[i+1] >> p[i+1];
  initial();
  cout << dojob(M,N) << endl;
  return 0;
}
