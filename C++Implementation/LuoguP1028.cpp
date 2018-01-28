#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,k;
int a[20];

int isprime(int n)
{
  if(n==1)
  return 0;
  if(n==2)
  return 1;
  double t = pow(n,0.5);
  For(2,t+1)
  if(n%i==0)
  return 0;
  return 1;
}

int dojob(int lefting, int now, int start, int end)
{
  if(lefting == 0)
    return isprime(now);
  int sum = 0;
  For(start,end-lefting+2)
  {
    sum+=dojob(lefting-1, now+a[i], i+1, end);
  }
  return sum;
}

int main()
{
  cin >> N >> k;
  For(0,N)
  cin >> a[i];
  cout << dojob(k,0,0,N-1) << endl;
  return 0;
}
