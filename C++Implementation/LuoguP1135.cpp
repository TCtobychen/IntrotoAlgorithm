#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int ans[210];
int d[210];
queue<int> q;
int N,A,B;

int dojob(int t)
{
  int flr=d[t];
  if(t-flr>0&&ans[t-flr]==-1)
    {q.push(t-flr);ans[t-flr]=ans[t]+1;}
  if(t+flr<=N&&ans[t+flr]==-1)
    {q.push(t+flr);ans[t+flr]=ans[t]+1;}
}

int main()
{
  memset(ans,-1,sizeof(ans));
  cin >> N >> A>>B;
  For(1,N+1)
  cin >> d[i];
  q.push(A);
  ans[A]=0;
  while(!q.empty())
  {
    int t=q.front();
    dojob(t);
    q.pop();
  }
  cout << ans[B] << endl;
  return 0;
}
