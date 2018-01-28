#include <iostream>
#include <cstring>
#include <cmath>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int d[10];

int isprime(int n )
{
  if(n==1)
  return 0;
  if(n==2)
  return 1;
  int t = pow(n,0.5);
  For(2,t+1)
  if(n%i==0)
  return 0;
  return 1;
}

int iscyc(int n )
{
  memset(d,0,sizeof(d));
  int k=0;
  while(n>0)
  {
    d[k]=n%10;
    n=n/10;
    k++;
  }
  k--;
  int j = 0;
  while(j<=k)
  {
    if(d[j]!=d[k])
      return 0;
    j++;k--;
  }
  return 1;
}

int test(int n)
{
  if(isprime(n)&&iscyc(n))
  return 1;
  return 0;
}

int main()
{
  long long int a,b;
  cin >> a>> b;
  int start=getd(a);
  int end=getd(b);
  return 0;
}
