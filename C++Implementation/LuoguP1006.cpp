#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int M,N;
int a[55][55];
int d[105][55][55];

int main()
{
  cin >> M >> N;
  For(0,M)
    for(int j=0;j<N;j++)
    cin >> a[i][j];
  memset(d,-1,sizeof(d));
  d[0][0][0]=0;
  d[1][0][1]=a[0][1]+a[1][0];
  For(2,M+N-2)
    for(int j = 0;j<=M-2;j++)
      for(int k=j+1;k<=M-1;k++)
      {
        int s1=-1;
        s1=max(s1,d[i-1][j][k]);
        s1=max(s1,d[i-1][j-1][k]);
        s1=max(s1,d[i-1][j-1][k-1]);
        if(k!=j+1)
          s1=max(s1,d[i-1][j][k-1]);
        if(s1==-1) continue;
        d[i][j][k]=s1+a[i-j][j]+a[i-k][k];
      }
  cout << d[M+N-3][M-2][M-1] << endl;
  return 0;
}
