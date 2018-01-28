#include <iostream>
#include <cstring>
#include <cmath>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int n;
int d[20000];

int isprime(int a)
{
  int t = pow(a,0.5);
  For(2,t+1)
  if(a%i==0)
  return 0;
  return 1;
}

void gen()
{
  For(3,n)
  d[i]=isprime(i);
}

int main()
{
  cin >> n;
  memset(d,0,sizeof(d));
  d[2]=1;
  gen();
  For(2,n/3)
  if(d[i]==1)
    for(int j = i;j<(n-i)/2+1;j++)
    if(d[j]==1)
      if(d[n-i-j]==1)
      {cout << i <<' ' << j << ' ' <<n-i-j<<endl;return 0;}
}
