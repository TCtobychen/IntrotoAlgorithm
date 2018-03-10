#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

struct person{
  int q,e;
}a[210];
int N,d[210][40010],s[210]={0};

bool comparison(person p1, person p2)
{return p1.e>p2.e;}

int main()
{
  cin >> N;
  For(0,N) cin >> a[i+1].q >> a[i+1].e;
  sort(a+1,a+N+1,comparison);
  For(1,N+1) s[i]=s[i-1]+a[i].q;
  For(0,N+1) for(int j=0;j<=s[N];j++) d[i][j]=100000;
  d[0][0]=0;
  For(1,N+1)
    for(int t=0;t<=s[i];t++)
    {
      if(t>=a[i].q) d[i][t]=min(d[i][t],max(d[i-1][t-a[i].q],t+a[i].e));
      if(s[i-1]>=t) d[i][t]=min(d[i][t],max(d[i-1][t],s[i-1]-t+a[i].q+a[i].e));
    }
  int ANS=100000;
  For(0,s[N]+1) ANS=min(d[N][i],ANS);
  cout << ANS << endl;
  return 0;
}
