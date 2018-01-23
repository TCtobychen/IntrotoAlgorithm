#include <iostream>
#define For(x,y) for(int i = x;i<y;i++)
#define For1(x,y) for(int j=x;j<y;j++)
using namespace std;
int d[30][30];
int c[30][30];
int s[30];
int N;


void Read()
{
  cin >> N;
  For(0,N)
    cin >> s[i];
  For(0,N)
    For1(0,N)
      d[i][j]=0;
}

int dojob(int a, int b)
{
  if(a>b)
    return 1;
  if(a==b)
    return s[a];
  if(d[a][b]>0)
    return d[a][b];
  int sum = 0;
  For(a+1,b+1)
    if(sum<dojob(a+1,i)*dojob(i+1,b))
    {
      c[a][b]=i;
      sum=dojob(a+1,i)*dojob(i+1,b);
    }
  sum+=s[a];
  return sum;
}

void print(int a, int b)
{
  if(a==b)
    {cout << a+1 << ' ';return ;}
  if(a>b)
    return ;
  int t=c[a][b];
  print(a+1,t);
  print(a,a);
  print(t+1,b);
}

int main()
{
  Read();
  cout << dojob(0,N-1) << endl; // start from 0, end at N-1
  print(0,N-1);
}
