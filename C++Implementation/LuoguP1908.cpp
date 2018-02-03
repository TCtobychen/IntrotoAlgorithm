#include <iostream>
#include <cstring>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int a[40010];
int n;

void output()
{
  For(0,n)
  cout << a[i] << ' ';
  cout << endl;
}

int dojob(int start, int end)
{
  if(start>=end-1)
    return 0;
  int mid=(start+end)/2;
  int sum1=dojob(start,mid);
  int sum2=dojob(mid,end);
  //output();
  int sum=sum1+sum2;
  int j=mid,i=start,last=start;
  int b[40010];
  memset(b,0,sizeof(b));
  while(i<mid || j<end)
  {
    if(i==mid)
    {
      b[last]=a[j];
      j++;last++;
      continue;
    }
    if(j==end)
    {
      b[last]=a[i];
      i++;last++;
      continue;
    }
    if(a[i]<=a[j])
    {
      b[last]=a[i];last++;i++;continue;
    }
    if(a[j]<a[i])
    {
      b[last]=a[j];sum+=(mid-i);j++;last++;
    }
  }
  //For(0,n)
  //cout << b[i] << ' ';
  //cout << endl;
  For(start,end)
    a[i]=b[i];
  return sum;
}

int main()
{
  cin  >> n;
  For(0,n)
  cin >> a[i];
  cout << dojob(0,n) << endl;
  //output();
  return 0;
}
