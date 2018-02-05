#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

// Now is 36 points on Luogu.

int d[3000][40][30];
int has[110];
int D,G;

struct item{
  int t,l,h;
};
item a[110];

bool comparison(item m1, item m2)
{
  if(m1.t==m2.t) return (m1.l+m1.h) <= (m2.l+m2.h);
  return m1.t<m2.t;
}

int dojob(int t0, int h0,int last, int len)
{
  if(d[t0][h0][len]>=0)
    return d[t0][h0][len];
  int hh=h0;
  while(a[last].t<=t0+len) {h0+=a[last].h;if(h0>=D) {d[t0][hh][len]=(a[last].t-t0); return (a[last].t-t0);}last++;}
  // If it gets here, then h0 < D and life is gonna end
  if(h0==0) return len;
  int ans=0;
  For(0,last)
    if(has[i]==0) {has[i]=-1;ans=max(ans,dojob(t0+len,h0-a[i].h,last,a[i].l));has[i]=0;}
  d[t0][hh][len]=ans+len;
  return ans+len;
}

int main()
{
  cin >> D >> G;
  For(0,G) {cin >> a[i].t >> a[i].l >> a[i].h;}
  memset(d,-1,sizeof(d));
  memset(has,0,sizeof(has));
  sort(a,a+G,comparison);
  cout << dojob(0,0,0,10) << endl;
  return 0;
}
