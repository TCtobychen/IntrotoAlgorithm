#include <iostream>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int n;

void print(int t, int j)
{
  if(t>0&&t!=1)
    cout << "+" << t << "x^" << j;
  if(t==1)
    cout <<"+" <<"x^" << j;
  if(t<0&&t!=-1)
    cout << t << "x^" << j;
  if(t==-1)
    cout << "-" << "x^"<<j;
}

int main()
{
  cin >> n;
  int t;
  cin >> t;
  if(t>0&&t!=1)
    cout << t << "x^" << n;
  if(t==1)
    cout <<"x^" << n;
  if(t<0)
    print(t,n);
  For(0,n-2)
  {
    cin >> t;
    print(t,n-i-1);
  }
  cin >> t;
  if(t>0&&t!=1)
    cout << "+" << t << "x" ;
  if(t==1)
    cout <<"+" <<"x" ;
  if(t<0&&t!=-1)
    cout << t << "x" ;
  if(t==-1)
    cout << "-" << "x";
  cin >>t ;
  if(t>0)
  cout << "+" << t << endl;
  if(t<0)
  cout << t << endl;
  return 0;
}
