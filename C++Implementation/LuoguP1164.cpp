#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int N,M;
int d[105][1010];
int a[105];

int dojob(int n, int m)
{
  //cout << n <<" " << m << endl;
  if(d[n][m]>=0)
    return d[n][m];
  d[n][m]=dojob(n-1,m);
  if(a[n]<=m)
    d[n][m]+=dojob(n-1,m-a[n]);
  return d[n][m];
}

void initial()
{
  memset(d,-1,sizeof(d));
  For(0,M+1)
  d[0][i]=0;
  For(0,N+1)
  d[i][0]=1;
}

int main()
{
  cin >> N >> M;
  For(0,N)
  cin >> a[i+1];
  initial();
  cout << dojob(N,M) << endl;
  return 0;
}
