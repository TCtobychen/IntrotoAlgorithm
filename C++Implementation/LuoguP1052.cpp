#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#define INF 1000;
#define For(x,y) for(long long int i=x;i<y;i++)
using namespace std;

long long int L,S,T;
int M;
int d[15];
long long int a[110];
set<int > s;

void initial()
{
  d[0]=0;
  For(1,S) d[i]=1000;
  For(S,T)
  {
    int ANS=INF;
    for(int j = i-S;j>=0;j--)
    {
      ANS=min(ANS,d[j]);
      //cout << i << ' ' << d[i] << endl;
    }
    d[i]=ANS+s.count(i);
    //cout << i << ' ' << d[i] << endl;
  }
  //For(0,T)
  //cout << i << ' ' << d[i] << endl;
}

void fill(int n)
{
  int j = n%T;
  if(j<0) j+=T;
  int ANS=INF;
  For(S,T+1)
  {
    int temp=j-i;
    if(temp<0) temp+=T;
    ANS=min(ANS,d[temp]);
    //cout << temp << ' ' << d[temp] << endl;
  }
  d[j]=ANS+s.count(n);
  //cout << n << ' '<<d[j] << endl;
}

int findleast()
{
  int s=INF;
  For(0,T) s=min(s,d[i]);
  return s;
}

int main()
{
  cin >> L >> S >> T >> M;
  int t,m=L;
  For(0,M) {cin >> t;a[i]=t;s.insert(t);m=min(m,t);}
  sort(a,a+M);
  if(S!=T){
  initial();
  int k=0;
  while(a[k]<T) k++;
  if((a[k]-T)>=T) For(0,T) d[i]=findleast();
  else For(T,a[k]) fill(i);
  For(k,M-1)
  {
    fill(a[i]);
    if((a[i+1]-a[i])>=(T+2)) For(0,T) d[i]=findleast();
    else for(int j =a[i]+1;j<a[i+1];j++) fill(j);
  }
  fill(a[M-1]);
  if(L+T-1-a[M-1] >=(T+2)) For(0,T) d[i]=findleast();
  else For(a[M-1]+1,L+T) fill(i);
  //For(T,L+T) {
    //fill(i);
    //cout << i << ' ' << d[i%T] << endl;}
  int ans=INF;
  For(0,T) ans=min(ans,d[i]);
  cout << ans << endl;}
  if(S==T)
  {
    int ans=0;
    For(0,M) if(a[i]%S==0) ans++;
    cout << ans << endl;
  }
  return 0;
}
