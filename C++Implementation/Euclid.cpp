#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
#define pair<int,int> pr
using namespace std;

int gcd(int a, int b)
{
  int t;
  while(b>0) t=a%b,a=b,b=t;
  return a;
}

void ext(int a,int b, int &x, int &y)
{
  if(b==0) {x=1,y=0;return ;}
  int x1,y1;
  ext(b,a%b,x1,y1);
  x=y1,y=x1-(a/b)*y1;
}

int main()
{
  int a,b,s,t;
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> a >> b;
  cin.close();
  int d=gcd(a,b);
  cout << d <<endl;
  ext(a,b,s,t);
  cout << s <<' ' <<t << endl;
  cout << sizeof(int) << endl;
  return 0;
}
