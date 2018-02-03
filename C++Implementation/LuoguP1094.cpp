#include <iostream>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int a[30010];

bool great(int i , int j)
{
  return i<j;
}

int main()
{
  int w,n,num=0;
  cin >> w>> n;
  For(0,n)
  cin >> a[i];
  sort(a,a+n,great);
  int i=0,j=n-1;
  while(i<j)
  {
    if(a[j]+a[i]<=w)
    {num++;j--;i++;}
    else
    {num++;j--;}
  }
  if(j==i) num++;
  cout << num << endl;
  return 0;
}
