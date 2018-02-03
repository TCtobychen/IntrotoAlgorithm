#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int N;
int a[200010];
int x=0,y=0;
long long int m=0;

void dojob(int n)
{
  //cout << "!!!";
  long long int t=a[n];
  long long int sum=t;
  int anchor=n;
  //cout << "???";
  for(int i=n-1;i>y;i--)
  {
    sum+=a[i];
    if(t<sum)
      {t=sum;anchor=i;}
  }
  //cout << anchor <<' ' << t << endl;
  //cout <<"HA";
  int mm=max(m+sum,m);
  mm=(mm>t)?mm:t;
  if(mm==m+sum)
  y=n;
  if(mm==t)
  {x=anchor;y=n;}
  m=mm;
}

int main()
{
  cin >> N;
  For(0,N)
  cin >> a[i];
  m=a[0];
  For(1,N)
//  {
    dojob(i);
//cout << x << ' '<<y <<' '<< m << endl;}
  cout << m << endl;
  return 0;
}
