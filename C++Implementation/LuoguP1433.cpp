#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define Maxn 1000000
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int N;
double d[20][20];
double c[20][2];
double sum=Maxn;
int vis[20];

void deal(int j)
{
  double x=c[j][0],y=c[j][1];
  double x1,y1;
  For(0,j)
  {
    x1=c[i][0];y1=c[i][1];
    d[i][j]=d[j][i]=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
  }
}

double dfs(int n, double len_now)
{
  //cout << len_now << endl;
  if(len_now>sum)
    return Maxn;
  double ans=Maxn;
  int ok=1;
  for(int i = N;i>0;i--)
  if(!vis[i])
  {
    ok=0;
    vis[i]=1;
    double left=(d[n][i]+dfs(i,len_now+d[n][i]));
    ans=(ans>left)?left:ans;
    vis[i]=0;
  }
  if(ok)
  {sum=(sum>len_now)?len_now:sum;return 0;}
  return ans;
}

int main()
{
  cin >> N;
  memset(d,0,sizeof(d));
  memset(vis,0,sizeof(vis));
  c[0][0]=c[0][1]=0;
  deal(0);
  For(1,N+1)
  {
    cin >> c[i][0] >> c[i][1];
    deal(i);
  }
  printf("%0.2lf",dfs(0,0));
  return 0;
}
