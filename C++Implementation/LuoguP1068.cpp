#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;

pair<int, int > p[5000];
int n,m;

bool comparison(pair<int, int >p1, pair<int ,int>p2)
{
  if(p1.first!=p2.first)
    return p1.first>p2.first;
  return p1.second < p2.second;
}

int main()
{
  cin >> n >> m;
  int input1,input2;
  For(0,n)
  {
    cin >> input1 >> input2;
    p[i].first=input2;
    p[i].second=input1;
  }
  //For(0,n)
  //cout << p[i].first << endl;
  sort(p,p+n,comparison);
  //For(0,n)
  //cout << p[i].first << endl;
  m=floor(m*1.5);
  int j=0;
  while(p[j].first>=p[m-1].first && j <n)
    j++;
  cout << p[m].first << ' '<< j << endl;
  j--;
  For(0,j+1)
  cout << p[i].second <<' '<< p[i].first << endl;
  return 0;
}
