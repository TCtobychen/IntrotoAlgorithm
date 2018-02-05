#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int M,N;
int d[110][110][110];
bool a[110][110];
int m[110];

int main()
{
  cin >> M >> N;
  For(0,M)
    for(int j=0;j<N;j++)
    {cin >> a[i][j];d[0][i][j]=a[i][j];}
  memset(m,0,sizeof(m));
  m[0]=1;
  For(1,min(M,N))
    for(int j=0;j<=M-1-i;j++)
      for(int k=0;k<=N-1-i;k++)
        if(d[i-1][j][k]&&d[i-1][j+1][k+1]&&a[j+i][k]&&a[j][k+i])
        {d[i][j][k]=1;m[i]=1;}
  for(int i=min(M,N)-1;i>=0;i--)
    if(m[i])
    {cout << i+1 << endl;return 0;}
  return 0;
}
