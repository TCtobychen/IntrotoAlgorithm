#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#define pr pair<long long int,long long int>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

pr d[1010][1010];
long long a[1010][1010];
int N,M,K;

int main()
{
  //ifstream cin("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M >> K;
  For(0,N) for(int j=0;j<M;j++) {cin >> a[i][j];d[i][j].first=d[i][j].second=a[i][j];}
  //cin.close();
  For(1,K)
    for(int x=0;x<=N-1-i;x++)
      for(int y=0;y<=M-1-i;y++)
      {
        long long int maxn=d[x][y].first, minn=d[x][y].second;
        maxn=max(maxn,d[x+1][y+1].first);maxn=max(maxn,a[x+i][y]);maxn=max(maxn,a[x][y+i]);
        minn=min(minn,d[x+1][y+1].second);minn=min(minn,a[x+i][y]);minn=min(minn,a[x][y+i]);
        d[x][y].first=maxn,d[x][y].second=minn;
      }
  long long int ANS=1000000000;
  For(0,N-K+1) for(int j=0;j<=M-K;j++) //{cout << d[i][j].first <<' '<<d[i][j].second<< endl;
    ANS=min(ANS,d[i][j].first-d[i][j].second);
  cout << ANS << endl;
  return 0;
}
