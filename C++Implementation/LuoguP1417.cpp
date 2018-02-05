#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

long long int d[100010];
int T,N;
long long int a[55],b[55],c[55];

struct item{
  long long int a,b,c;
};
item m[55];

bool comparison(item m1, item m2)
{
  return m1.c*m2.b < m2.c * m1.b;
}

int main()
{
  cin  >> T>> N;
  For(0,N)
  cin >> m[i+1].a;
  For(0,N)
  cin >> m[i+1].b;
  int sumt=0;
  For(0,N)
  {cin >> m[i+1].c;sumt+=m[i+1].c;}
  //cout << "!!!" << endl;
  sort(m+1,m+N+1,comparison);
  T=min(T,sumt);
  //cout <<"???" << endl;
  memset(d,-1,sizeof(d));
  d[0]=0;
  For(1,N+1)
    for(int j = T;j>=m[i].c;j--)
      d[j]=max(d[j],d[j-m[i].c]+m[i].a-j*m[i].b);
  long long int ans=0;
  For(1,T+1)
  ans=max(ans,d[i]);
  cout << ans << endl;
  return 0;
}
