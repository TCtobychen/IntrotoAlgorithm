#include <iostream>
#include <cstring>
#include <cmath>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N;

void dojob(int n )
{
  if(n==3)
    {cout << "2+2(0)";return; }
  if(n==2)
    {cout << "2";return ;}
  if(n==1)
    {cout << "2(0)";return ;}
  if(n==0)
    return ;
    int a=0;
    while(pow(2,a)<=n)
    a++;
    a--;
    n-=pow(2,a);
    cout << "2(";
    dojob(a);
    cout << ")";
    if(n!=0)
    cout <<"+";
    dojob(n);

}

int main()
{
  cin >> N;
  //For(0,10){
    dojob(N);
  cout << endl;
  //}
  return 0;
}
