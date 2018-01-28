#include <iostream>
#include <cstring>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int n;
int a[100];

int main()
{
  cin >> n;
  int sum =0,number=0;
  For(0,n)
    {cin >> a[i];sum+=a[i];}
  int e=sum/n;
  For(0,n-1)
    if(a[i]!=e)
    {
      number++;
      //a[i]=e;
      a[i+1]+=(a[i]-e);
    }
  cout << number << endl;
  return 0;
}
