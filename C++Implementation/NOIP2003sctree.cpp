#include <iostream>
#include <cstdio>
#include <algorithm>
#define For(x,y) for(int i = x;i<y;i++)
#define For1(x,y) for(int j=x;j<y;j++)
using namespace std;
long long int d[30][30];
int c[30][30];
int s[30];
int N;


void Read()
{
  cin >> N;
  For(0,N)
    cin >> s[i];
  memset(d,0,sizeof(d));
}

int dojob(int a, int b)
{
  if(d[a][b]>0)
    return d[a][b];
  if(a>b)
    return 1;
  if(a==b)
    {d[a][b]=s[a];return s[a];}
  int sum = 0;
  For(a,b)
  {
    int temp = dojob(a,i-1)*dojob(i+1,b)+s[i];
    if(sum<temp)
    {
      c[a][b]=i;
      sum=temp;
    }
  }
  d[a][b]=sum;
  return sum;
}

void print(int a, int b)
{
  if(a==b)
    {cout << a+1 << ' ';return ;}
  if(a>b)
    return ;
  int t=c[a][b];
  print(t,t);
  print(a,t-1);
  print(t+1,b);
}

int main()
{
  Read();
  cout << dojob(0,N-1) << endl; // start from 0, end at N-1
  print(0,N-1);
}
