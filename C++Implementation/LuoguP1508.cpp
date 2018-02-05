#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

long long int d[210][210];
int N,M;
long long int a[210][210];

//cout << m << ' '<< n << ' '<<d[m][n]<<endl;

long long int dojob(int m, int n)
{
  if(d[m][n]!=-1)
    {return d[m][n];}
  if(n==0)
  {d[m][n]=max(dojob(m+1,0),dojob(m+1,1))+a[m][n];return d[m][n];}
  if(n==N-1)
  {d[m][n]=max(dojob(m+1,N-1),dojob(m+1,N-2))+a[m][n];return d[m][n];}
  d[m][n]=max(dojob(m+1,n-1),dojob(m+1,n));d[m][n]=max(d[m][n],dojob(m+1,n+1));d[m][n]+=a[m][n];return d[m][n];
}

void initial()
{
  memset(d,-1,sizeof(d));
  For(0,N)
  d[M-1][i]=-1000000000;
  For(N/2-1,N/2+2)
  d[M-1][i]=a[M-1][i];
}

int main()
{
  cin >> M >> N;
  For(0,M)
    for(int j =0;j<N;j++)
    cin >> a[i][j];
  long long int sum=0;
  if(N!=1){
  initial();
  //cout << dojob(0,1) << endl;
  For(0,N)
  //cout << dojob(0,i) << endl;
  sum=max(sum,dojob(0,i));}
  if(N==1)
  For(0,M)
  sum+=a[i][0];
  cout << sum << endl;
  return 0;
}
