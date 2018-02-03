#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cmath>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

stack<int> s[12];
int N;

void output(int k)
{
  switch (k) {
    case 0: {cout << 'B';break;}
    case 1: {cout << 'I';break;}
    case 2: {cout << 'F';break;}
  }
}

void dojob(int n, int t)
{
  output(t);
  if(s[n].size()==1)
  {
    int k=s[n].top();
    s[n].pop();
    if(t==k)
      dojob(n+1,t);
    if(t!=k)
      dojob(n+1,2);
    return ;
  }
  if(s[n].size()==0)
    s[n].push(t);
}

int main()
{
  cin >> N;
  int t;
  For(0,pow(2,N))
  {
    scanf("%1d",&t);
    dojob(0,t);
  }
  return 0;
}
