#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(long long int i=x;i<y;i++)
using namespace std;

long long int N,M,last=0;
long long int ans=0,CONS=19260817;
long long int aft[510];
struct item{
long long int k,d;
}a[510];

bool comparison(item m1, item m2)
{
  return m1.d>m2.d;
}

void dfs(long long int cur, long long int left)
{
  long long int temp;
  if(cur==N) {if(left-last<0) ans++;return;}
  if(cur==N-3) ans=ans%CONS;
  long long int up=left/a[cur].d;up=min(up,a[cur].k);long long int down=0;
  if(left>=(aft[cur+1]+a[cur].d)) down=(left-aft[cur+1])/a[cur].d; // left-aft[cur+1]-a[cur].d <a[cur].d*down <= left-aft[cur+1]
  down=min(down,a[cur].k);
  for(long long int i=up;i>=down;i--) {if(i!=a[cur].k) last=a[cur].d;temp=ans;dfs(cur+1,left-a[cur].d*i);if(temp==ans)break;}
}

int main()
{
  cin >> N >> M;
  For(0,N) cin >> a[i].k >> a[i].d;
  sort(a,a+N,comparison);
  aft[N]=0;
  for(long long int i=N-1;i>=0;i--) {aft[i]=aft[i+1]+a[i].k*a[i].d;if(aft[i]>M) {for(long long int j=0;j<=i;j++) aft[j]=M+1;break;}}
  dfs(0,M);
  cout << ans << endl;
  return 0;
}
