#include <iostream>
#include <cstring>
#include <cmath>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int main()
{
  double p=1e8,cst=pow(2,55);
  For(0,30000){
    p*=(1-i/cst);
  }
  cout << 1e8-p << endl;
  return 0;
}
