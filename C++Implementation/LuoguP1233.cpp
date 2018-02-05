#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int ans=0;
int N;
pair<int, int > a[5010];
int last[5010];


bool comparison(pair<int, int > p1, pair<int, int > p2)
{
  if(p1.first!=p2.first) return p1.first < p2.first;
  return p1.second < p2.second;
}

int main()
{
  cin >> N;
  For(0,N) cin >> a[i].first >> a[i].second;
  sort(a,a+N,comparison);
  For(0,N)
  {
    int ok=0;
    for(int j =0;j<ans;j++)
      if(a[i].second>=last[j])
        {last[j]=a[i].second;ok=1;break;}
    if(!ok)
    {last[ans]=a[i].second;ans++;}
  }
  cout << ans << endl;
  return 0;
}
