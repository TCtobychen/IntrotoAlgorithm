#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int d[2510][2510][2];
bool a[2510][2510];
int countt[2510];
int M,N;

int main()
{
  cin >> M >> N;
  memset(d,0,sizeof(d));
  memset(countt,0,sizeof(countt));
  countt[0]=1;
  For(0,M)
    for(int j =0;j<N;j++)
    {scanf("%d",&a[i][j]);if(a[i][j]==1) {d[i][j][0]=d[i][j][1]=1;countt[1]=1;}}
  For(2,min(M,N)+1)
    for(int j=0;j<=M-i;j++)
      for(int k=0;k<=N-i;k++)
          if(d[j][k][0]==i-1)
          if(d[j+1][k+1][0]==i-1 && a[j+i-1][k]==0 && a[j][k+i-1]==0)
          {d[j][k][0]++;countt[i]=1;}
  For(2,min(M,N)+1)
   for(int j=0;j<=M-i;j++)
     for(int k=N-1;k>=i-1;k--)
      {
        if(d[j][k][1]==i-1)
        if(d[j+1][k-1][1]==i-1 && a[j+i-1][k]==0 && a[j][k-i+1]==0)
        {d[j][k][1]++;countt[i]=1;}
      }
  for(int i =min(M,N);i>=0;i--)
    if(countt[i]==1)
      {cout << i << endl;break;}
  return 0;
}
