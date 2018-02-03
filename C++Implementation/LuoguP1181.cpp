#include <iostream>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;

int main()
{
  int n,t,number=0,sum=0;
  long long int m;
  cin >> n >> m;
  For(0,n)
  {
    cin >> t;
    if((sum+t)>m)
    {
      number++;
      sum=t;
    }
    else
      sum+=t;
  }
  if(sum>0)
  number++;
  cout << number << endl;
  return 0;
}
