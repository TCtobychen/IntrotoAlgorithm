#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M;
int a[50010];
int m=0;

// Wrong for low efficiency

void incr()
{
  int t=N-2;
  while(a[t]>a[t+1]) t--;
  int j;
  for(j =N-1;j>=t+1;j--) if(a[j]>a[t]) break; //t=N-2, j=N-1, num=1, m=0, m=-1, m=2;
  int s=a[t];a[t]=a[j];a[j]=s;
  int num=N-t-1;                    // t=N-3, j=N-1, num=2, m=0, m=-2,
  m-=num*(num-1)/2;
  m-=(N-(j+1));
  m+=(num-(j-t-1));
  sort(a+t+1,a+N);
}

void output()
{
  For(0,N) cout << a[i] <<' '; cout << endl;
}

int main()
{
  cin >> N >> M;
  For(0,N) a[i]=i+1;
  while(m!=M) {incr();}
  output();
  return 0;
}
