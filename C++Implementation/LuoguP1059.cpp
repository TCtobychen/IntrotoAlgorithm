#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int a[1000000];

int main()
{
  set<int> s;
  int n;
  cin >> n;
  int t,c=0;
  For(0,n)
  {
    cin >> t;
    if(!s.count(t))
    {
      a[c]=t;
      c++;
      s.insert(t);
    }
  }
  sort(a,a+c);
  cout << c << endl;
  For(0,c)
  cout << a[i] << ' ';
  cout << endl;
  return 0;
}
