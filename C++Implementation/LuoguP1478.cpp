#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
  int n,s,a,b,c,d;
  cin >> n >> s;
  cin >> a>> b;
  b=a+b;
  For(0,n)
  {
    cin >> c >>d;
    if(c<=b)
    q.push(d);
  }
  int number=0;
  while(!q.empty()&&s>=0)
  {
    int t=q.top();
    s-=t;
    if(s>=0)
    number++;
    q.pop();
  }
  cout << number << endl;
  return 0;
}
