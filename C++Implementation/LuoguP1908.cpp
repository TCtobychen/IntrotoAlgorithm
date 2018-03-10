#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,a[40010],c[400000];
const int MAXN=sizeof(int);

int lowbit(int x) {return x&(-x);}

void add(int index, int v)
{
  while(index<=MAXN) {c[index]+=v;index+=lowbit(index);}
}

int sum(int index)
{
  return index?c[index]+sum(index-lowbit(index)):0;
}

int main()
{
  //ifstream cin;
  //cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  memset(c,0,sizeof(c));
  cin >> N;
  For(0,N) cin >> a[i];
  //cin.close();
  int cnt=0;
  for(int i=N-1;i>=0;i--) {cnt+=sum(a[i]);add(a[i],1);}
  //For(0,20) cout << c[i] << ' '; cout << endl;
  cout << cnt << endl;
  return 0;
}
