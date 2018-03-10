#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int d[110][110][12];
int p[110][12];
int a[110][2];
int N,M,K;

int dojob(int n, int m, int k)
{
  if(d[n][m][k]>=0) return d[n][m][k];
  if(k==0) {d[n][m][k]=0;return 0;}
  int ans=0,temp=0;
  // First we solve the single line case:
  for(int i=n-1;i>=max(0,k-m);i--) {temp+=a[i+1][1];ans=max(ans,dojob(i,m,k));ans=max(ans,dojob(i,m,k-1)+temp);}
  if(k-m-1>=0) ans=max(ans,dojob(k-m-1,m,k-1)+temp+a[k-m][1]); temp=0;
  for(int i=m-1;i>=max(0,k-n);i--) {temp+=a[i+1][0];ans=max(ans,dojob(n,i,k));ans=max(ans,dojob(n,i,k-1)+temp);}
  if(k-n-1>=0) ans=max(ans,dojob(n,k-n-1,k-1)+temp+a[k-n][0]); temp=0;
  // Then the two lines case:
  if(n==m) {
    for(int i=n-1;i>=(k+1)/2;i--) {temp+=a[i+1][1]+a[i+1][0];ans=max(ans,dojob(i,i,k-1)+temp);ans=max(ans,dojob(i,i,k));}
    int t=(k-1)/2;temp+=a[t+1][0]+a[t+1][1];ans=max(ans,dojob(t,t,k-1)+temp);
  }
  d[n][m][k]=ans;
  return ans;
}

int dojob1(int n, int k)
{
  if(p[n][k]>=0) return p[n][k];
  if(k==0) {p[n][k]=0;return 0;}
  int temp=0,ans=0;
  for(int i=n-1;i>=k;i--) {temp+=a[i+1][0];ans=max(ans,dojob1(i,k-1)+temp);ans=max(ans,dojob1(i,k));}
  temp+=a[k][0];ans=max(ans,dojob1(k-1,k-1)+temp);
  p[n][k]=ans;
  return ans;
}

int main()
{
  cin >> N >> M >> K;
  For(0,N) for(int j=0;j<M;j++) cin >> a[i+1][j];
  memset(d,-1,sizeof(d));
  memset(p,-1,sizeof(p));
  d[0][0][0]=0;p[0][0]=0;
  //cout << dojob(2,2,1) << endl;
  if(M==2) cout << dojob(N,N,K) << endl;
  else cout << dojob1(N,K) << endl;
  return 0;
}
