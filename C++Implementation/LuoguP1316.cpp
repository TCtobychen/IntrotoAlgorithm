#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int A, B;
long long int a[100010];

int num(int d) // The max distance between any two is bigger or equal to d
{
  int ans=1,last=0,j=1;
  while(j<A)
  {
    while(a[j]<a[last]+d && j<A)
    j++;
    if(j!=A)
    {last=j;ans++;}
  }
  return ans;
}

int dojob(int l, int r)
{
  if(l==r)
    return l;
  int mid=(l+r+1)/2;
  //cout << mid <<' '<<num(mid) << endl;
  if(num(mid)<B)
    return dojob(l,mid-1);
  else
    return dojob(mid,r);
}

int main()
{
  cin >> A >> B;
  For(0,A)
  cin >> a[i];
  sort(a,a+A);
  long long int l=10000000;
  For(0,A-1)
    l=min(l,a[i+1]-a[i]);
  int r=a[A-1]-a[0];
  cout << dojob(l,r) << endl;
  return 0;
}
