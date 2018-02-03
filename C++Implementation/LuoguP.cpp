#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int d[60][32010],nu[60];
int v[60][3],p[60][3],c[60];
int M,N;

int dojob(int n, int m)
{
  //cout << n << ' '<< m << endl;
  if(d[n][m]>=0)
    return d[n][m];
  if(c[n]==0)
    {
      if(m>=v[n][0])
      d[n][m]=max(dojob(n-1,m),v[n][0]*p[n][0]+dojob(n-1,m-v[n][0]));
      else
      d[n][m]=dojob(n-1,m);
      return d[n][m];
    }
  if(c[n]==1)
    {
      if(m<v[n][0])
      d[n][m]=dojob(n-1,m);
      if(m>=v[n][0])
      {
        d[n][m]=max(dojob(n-1,m),v[n][0]*p[n][0]+dojob(n-1,m-v[n][0]));
        if(m>=v[n][0]+v[n][1])
          d[n][m]=max(d[n][m],v[n][0]*p[n][0]+v[n][1]*p[n][1]+dojob(n-1,m-v[n][0]-v[n][1]));
      }
      return d[n][m];
    }
  if(c[n]==2)
    {
      if(m<v[n][0])
      d[n][m]=dojob(n-1,m);
      if(m>=v[n][0])
      {
        d[n][m]=max(dojob(n-1,m),v[n][0]*p[n][0]+dojob(n-1,m-v[n][0]));
        if(m>=v[n][0]+v[n][1])
          d[n][m]=max(d[n][m],v[n][0]*p[n][0]+v[n][1]*p[n][1]+dojob(n-1,m-v[n][0]-v[n][1]));
        if(m>=v[n][0]+v[n][2])
          d[n][m]=max(d[n][m],v[n][0]*p[n][0]+v[n][2]*p[n][2]+dojob(n-1,m-v[n][0]-v[n][2]));
        if(m>=v[n][0]+v[n][2]+v[n][1])
          d[n][m]=max(d[n][m],v[n][0]*p[n][0]+v[n][2]*p[n][2]+v[n][1]*p[n][1]+dojob(n-1,m-v[n][0]-v[n][2]-v[n][1]));
      }
      return d[n][m];
    }
  return d[n][m];
}

int main()
{
  cin >> M >> N;
  int v0,p0,q,num=1;
  memset(c,0,sizeof(0));
  For(0,N)
  {
    cin >> v0 >>p0 >> q;
    if(q==0)
      {v[num][0]=v0;
      p[num][0]=p0;nu[i+1]=num;num++;}
    if(q!=0)
      {c[nu[q]]++;v[nu[q]][c[nu[q]]]=v0;p[nu[q]][c[nu[q]]]=p0;}
  }
  num--;
  memset(d,-1,sizeof(d));
  For(0,num)
  d[i][0]=0;
  For(0,M+1)
  d[0][i]=0;
  cout << dojob(num,M) << endl;
  return 0;
}
