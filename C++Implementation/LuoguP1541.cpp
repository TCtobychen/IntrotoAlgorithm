#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int d[130][43][43][43];
int a[360];
int num[5];
int N,M;

int main()
{
  cin >> N >> M;
  memset(num,0,sizeof(num));
  memset(d,0,sizeof(d));
  For(0,N) cin >> a[i];
  d[0][0][0][0]=a[0];
  int t;
  For(0,M) {cin >> t;num[t]++;}
  For(1,M+1)
    for(int x=0;x<=num[1];x++)
      for(int y=0;y<=num[2];y++)
        for(int z=0;z<=num[3];z++)
          if(!(i-x-y-z>num[4]))
          {
            //cout << i<<' '<<x << ' ' << y <<' ' <<z << endl;
            int ans=0;
            if(x>0) ans=max(ans,d[i-1][x-1][y][z]);
            if(y>0) ans=max(ans,d[i-1][x][y-1][z]);
            if(z>0) ans=max(ans,d[i-1][x][y][z-1]);
            if(i>x+y+z) ans=max(ans,d[i-1][x][y][z]);
            d[i][x][y][z]=ans+a[x+2*y+3*z+4*(i-x-y-z)];
          }
  cout << d[M][num[1]][num[2]][num[3]] << endl;
  return 0;
}
