#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int A,B,C;
int d[10];

void gett(int n)
{
  For(0,3)
  {
    d[n%10]=1;
    n=n/10;
  }
}

int test(int n )
{
  memset(d,0,sizeof(d));
  gett(n*A);
  gett(n*B);
  gett(n*C);
  For(1,10)
  if(d[i]==0)
  return 0;
  return 1;
}

int main()
{
  cin >>A >>B>>C;
  int ok = 0;
  int sum=A+B+C;
  int down=min((6*100+15*10+7+8+9)/sum,123/A);
  int up = min((24*100+15*10+6)/sum,999/C);
  For(down,up+1)
  if(test(i))
  {cout << i*A <<' '<< i*B <<' '<<i*C <<endl;ok=1;}
  if(!ok)
  cout << "No!!!" << endl;
  return 0;
}
