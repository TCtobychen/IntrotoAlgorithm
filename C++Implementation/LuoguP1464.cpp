#include <iostream>
#include <cstring>
#define For(x,y) for(int i = x;i<y;i++)
using namespace std;

int d[30][30][30];
int vis[30][30][30];

int dojob(int a, int b, int c)
{
  if(a<=0 || b <= 0 || c<=0)
    return 1;
  if(a>20||b>20||c>20)
    return dojob(20,20,20);
  if(vis[a][b][c])
    return d[a][b][c];
  if(a<b&&b<c)
  {
    vis[a][b][c]=1;
    d[a][b][c]=dojob(a,b,c-1)+dojob(a,b-1,c-1)-dojob(a,b-1,c);
    return d[a][b][c];
  }
  vis[a][b][c]=1;
  d[a][b][c]=dojob(a-1,b,c)+dojob(a-1,b-1,c)+dojob(a-1,b,c-1)-dojob(a-1,b-1,c-1);
  return d[a][b][c];
}

void print(int a, int b, int c, int ans)
{
  cout << "w(" << a <<", "<<b<<", "<<c<<") = "<<ans<<endl;
}

int main()
{
  memset(vis,0,sizeof(vis));
  int a,b,c;
  while(cin >> a >> b >> c)
  {
    if(a==-1&&b==-1&&c==-1)
    return 0;
    int ans=dojob(a,b,c);
    print(a,b,c,ans);
  }
}
