#include <iostream>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;

long long int A[1010];

int main()
{
  long long int n;
  int m;
  cin >> n >> m;
  int t1;long long int t2;
  memset(A,0,sizeof(A));
  For(0,m)
  {
    cin >> t1 >>t2;
    A[t1]+=t2;
  }
  long long int num=0,price=0;
  int t=0;
  while(num<n)
  {
    price+=t*A[t];
    num+=A[t];
    t++;
  }
  //cout << price <<' '<<num<<' '<<t <<endl;
  price-=(num-n)*(t-1);
  cout << price << endl;
  return 0;
}
