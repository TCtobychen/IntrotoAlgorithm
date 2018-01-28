#include <iostream>
#include <queue>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

queue<int> q;
int n,m;

int fd(int a)
{
  int ok=0;
  int size=q.size();
  while(size--)
  {
    int temp=q.front();
    if(temp==a)
    ok=1;
    q.pop();
    q.push(temp);
  }
  return ok;
}

int main()
{
  cin >> n >> m;
  int a;
  int num=0;
  For(0,m)
  {
    cin >> a;
    if(!fd(a))
    {
      num++;
      if(q.size()<n)
      q.push(a);
      else
      {
        q.pop();
        q.push(a);
      }
    }
  }
  cout << num << endl;
}
