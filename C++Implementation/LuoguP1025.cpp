#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int s[210][6][200];
int vis[210][6][200];
//int f[210][6][200];
int N,K;

int sjob(int n, int k, int m)
{
  //cout << n << ' '<< k <<' '<< m << endl;
  if(vis[n][k][m])
    return s[n][k][m];
  int sum=0;
  int b=min(m,n-k+1);
  For(1,b+1)
  {sum+=sjob(n-i,k-1,i);}
  s[n][k][m]=sum;
  vis[n][k][m]=1;
  return sum;
}

void initial()
{
  For(1,N+1)
    for(int j = 0;j<=N-K+1;j++)
    {//cout << i <<' '<<j << endl;
      s[i][0][j]=0;vis[i][0][j]=1;
      if(i>j) {s[i][1][j]=0;vis[i][1][j]=1;}
      else {s[i][1][j]=1;vis[i][1][j]=1;}
    }
}

int main()
{
  memset(s,-1,sizeof(s));
  memset(vis,0,sizeof(vis));
  initial();
  cin >> N >> K;
  initial();
  //cout << "START" << endl;
  cout << sjob(N,K,N-K+1) << endl;
  return 0;
}
