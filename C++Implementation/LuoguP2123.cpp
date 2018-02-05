#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

pair<long long int ,long long int > a[20010];
long long int ans,sum;
int T,N;

bool comparison(pair<long long int, long long int> p1, pair<long long int, long long int> p2)
{
  return min(p1.first,p2.second) < min(p1.second, p2.first);
}

int main()
{
  cin >> T;
  while(T--)
  {
    cin >> N;
    For(0,N) cin >> a[i].first >> a[i].second;
    sort(a,a+N,comparison);
    //For(0,N) cout << a[i].first << endl;
    ans=a[0].first+a[0].second;sum=a[0].first;
    For(1,N) {sum+=a[i].first;ans=max(ans,sum)+a[i].second;}
    cout << ans << endl;
  }
}
