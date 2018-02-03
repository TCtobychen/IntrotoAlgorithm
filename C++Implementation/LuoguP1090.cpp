#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int a[10010];

int main()
{
  long long int sum=0;
  int n;
  cin >> n;
  For(0,n)
  cin >> a[i];
  sort(a,a+n);
  For(0,n-1)
  {
    sum+=a[i]+a[i+1];
    a[i+1]+=a[i];
    int j;
    for(j = i+2;j<n;j++)
      if(a[j]>a[i+1])
        break;
    int t=a[i+1];
    for(int k =i+1;k<j-1;k++)
    a[k]=a[k+1];
    a[j-1]=t;
  }
  cout << sum <<endl;
  return 0;
}
