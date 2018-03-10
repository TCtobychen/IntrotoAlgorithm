#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int d[55][55][2];
int s[55],w[55],upto[55],downto[55];
int N,C;

int dfs(int start, int end, int t)
{
  //cout << start << ' ' << end << ' '<< t << endl;
  int ans;
  if(d[start][end][t]>=0) return d[start][end][t];
  if(t==1){
    ans=min(dfs(start,end-1,0)+(s[end]-s[start])*(upto[start-1]+downto[end]),dfs(start,end-1,1)+(s[end]-s[end-1])*(upto[start-1]+downto[end]));
    d[start][end][t]=ans;return ans;
  }
  if(t==0){
    ans=min(dfs(start+1,end,0)+(s[start+1]-s[start])*(upto[start]+downto[end+1]),dfs(start+1,end,1)+(s[end]-s[start])*(upto[start]+downto[end+1]));
    d[start][end][t]=ans;return ans;
  }
}

void initial()
{
  memset(d,-1,sizeof(d));
  int sum=0;
  For(0,N) sum+=w[i],upto[i]=sum; sum=0;
  For(0,N) sum+=w[N-1-i],downto[N-1-i]=sum; sum=0;
  upto[-1]=0;downto[N]=0;
  d[C][C][0]=d[C][C][1]=0;
  For(C+1,N) d[C][i][1]=d[C][i-1][1]+(s[i]-s[i-1])*(upto[C-1]+downto[i]),d[C][i][0]=d[C][i][1]+(s[i]-s[C])*(upto[C-1]+downto[i+1]);
  for(int i=C-1;i>=0;i--) d[i][C][0]=d[i+1][C][0]+(s[i+1]-s[i])*(upto[i]+downto[C+1]),d[i][C][1]=d[i][C][0]+(s[C]-s[i])*(upto[i-1]+downto[C+1]);
}

int main()
{
  cin >> N >> C;C--;
  For(0,N) cin >> s[i] >> w[i];
  initial();
  cout << min(dfs(0,N-1,0),dfs(0,N-1,1)) << endl;
  return 0;
}
