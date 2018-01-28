#include <iostream>
#include <cstring>
#define For(x,y) for(int i = x;i<y;i++)
using namespace std;

int n,x0,y0;
int d[10000][4];

int test(int t)
{
  if(x0>=d[t][0]&&x0<=d[t][0]+d[t][2]&&y0>=d[t][1]&&y0<=d[t][1]+d[t][3])
    return 1;
  return 0;
}

int main()
{
  cin >> n;
  int x,y;
  For(0,n)
  cin >> d[i][0] >> d[i][1] >> d[i][2] >> d[i][3];
  cin >> x0 >> y0;
  int top=-1;
  For(0,n)
  if(test(i))
    top=i+1;
  cout << top << endl;
}
