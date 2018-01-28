#include <iostream>
#include <cstring>
#include <cmath>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;

int gettime(double d)
{
  int t = 0;
  double dd=0;
  while(dd<d)
  {
    dd+=7*pow(0.98,t);
    t++;
  }
  return t;
}

int main()
{
  double s,x;
  cin >>s>>x;
  int t1=gettime(s-x);
  int t2=gettime(s+x);
  if(t2==t1+1)
  cout << 'n' << endl;
  else
  cout << 'y' << endl;
  return 0;
}
