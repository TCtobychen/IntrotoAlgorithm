#include <iostream>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int s[35][35];
int vis[35][35];
int N,M;

int sjob(int n, int m)
{
  //cout << n <<' ' << m << endl;
  if(vis[n][m])
    return s[n][m];
  int sum=0;
  if(m==1)
    sum=sjob(n-1,N)+sjob(n-1,2);
  if(m==N)
    sum=sjob(n-1,1)+sjob(n-1,N-1);
  if(m>1&&m<N)
    sum=sjob(n-1,m-1)+sjob(n-1,m+1);
  vis[n][m]=1;
  s[n][m]=sum;
  return sum;
}

void initial()
{
  memset(vis,0,sizeof(vis));
  For(2,N+1)
  s[0][i]=0;
  s[0][1]=1;
  For(1,N+1)
  vis[0][i]=1;
}

int main()
{
  cin >> N >> M;
  initial();
  cout << sjob(M,1) << endl;
  return 0;
}
