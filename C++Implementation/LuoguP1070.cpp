#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int coin[1010][1010],N,M,P;
long long int d[1005],cost[1005];

int walk(int start, int wt, int ps)
{
  int ans=0;
  For(0,ps){
    ans+=coin[start][wt+i];
    if(start==N) start=1;
    else start++;
  }
  return ans;
}
void output()
{
  For(0,M+1) cout << d[i] <<' ';cout << endl;
}
int main()
{
  cin >> N >> M >> P;
  For(0,N) for(int j=0;j<M;j++) scanf("%d",&coin[i+1][j]);
  long long int minn=100;
  For(0,N) {scanf("%lld",&cost[i+1]);minn=min(cost[i+1],minn);}
  d[M]=0;For(0,M) d[i]=-minn;
  for(int t=M-1;t>=0;t--)
    For(1,N+1) {long long int bonus=0;for(int p=1;p<=min(P,M-t);p++) {if(i+p-1==N) bonus+=coin[N][t+p-1]; else bonus+=coin[(i+p-1)%N][t+p-1]; d[t]=max(d[t],d[t+p]+bonus-cost[i]);}}
  //long long int ANS=0;
  //For(0,M) ANS=max(ANS,d[i]);
  //output();
  cout << d[0] << endl;
  return 0;
}
