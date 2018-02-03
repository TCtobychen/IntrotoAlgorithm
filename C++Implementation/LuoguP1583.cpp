#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;

int n,k;
int E[10];
pair<int, int> p[20000];

bool comparison(pair<int , int > p1, pair<int , int > p2)
{
  if(p1.first!=p2.first)
    return p1.first > p2.first;
  return p1.second < p2.second;
}

void output(int j)
{
  For(0,j)
  cout << p[i].first << ' '<< p[i].second << endl;
}

int main()
{
  cin >> n >> k;
  int t;
  For(0,10)
  cin >> E[i];
  For(0,n)
  {
    cin >> t;
    p[i].first=t;p[i].second=i;
  }
  //output(n);
  sort(p,p+n,comparison);
  //output(n);
  For(0,n)
  {p[i].first+=E[i%10];}
  //output(n);
  sort(p,p+n,comparison);
  //output(n);
  For(0,k)
  //cout << p[i].first << endl;
  cout << p[i].second + 1 <<' ';
  cout << endl;
  return 0;
}
