#include <iostream>
#include <cstring>
#include <queue>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

queue<int *> q;
int N,number=0;
int s[10];

void dojob1(int n, int num)
{
  if(n<num || n>3*num)
  return ;
  if(num==1)
  {
    number++;
    return;
  }
  For(1,4)
  {
    s[10-num]=i;
    dojob1(n-i,num-1);
  }
}
void dojob2(int n, int num)
{
  if(n<num || n>3*num)
  return ;
  if(num==1)
  {
    For(0,9)
    cout << s[i] << ' ';
    cout << n << endl;
    return;
  }
  For(1,4)
  {
    s[10-num]=i;
    dojob2(n-i,num-1);
  }
}

int main()
{
  cin >> N;
  if(N<10 || N >30)
  {cout << 0 << endl; return 0;}
  dojob1(N,10);
  cout << number << endl;
  memset(s,0,sizeof(s));
  dojob2(N,10);
  return 0;
}
