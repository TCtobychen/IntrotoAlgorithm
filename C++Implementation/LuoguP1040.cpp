#include <iostream>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int a[33];
long long int d[33][33];
int c[33][33];
int n;

int dojob(int start, int end)
{
  if(d[start][end]>0)
    return d[start][end];
  if(start==end-1)
    return a[start];
  if(start==end)
    return 1;
  int ans=0;
  For(start,end-1)
    if(ans<a[i]+dojob(start,i)*dojob(i+1,end))
    {
      ans=a[i]+dojob(start,i)*dojob(i+1,end);
      c[start][end]=i;
    }
  d[start][end]=ans;
  return ans;
}

void print(int start, int end)
{
  if(start>=end)
    return ;
  if(start==end-1)
    {cout << start +1<< ' ';return ;}
  cout << c[start][end]+1 << ' ';
  print(start,c[start][end]);
  print(c[start][end]+1,end);
}

int main()
{
  cin >> n;
  memset(d,0,sizeof(d));
  memset(c,0,sizeof(c));
  For(0,n)
  cin >> a[i];
  cout << dojob(0,n) << endl;
  print(0,n);
  return 0;
}
