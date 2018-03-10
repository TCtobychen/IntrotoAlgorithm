#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
#define ll long long int
using namespace std;

int T,N;

int calc(int cnt, int x, int y, int z)
{
  if(x>0 || z%2==1) return 1;
  else return 0;
}

void dojob()
{
  cin >> N;
  ll a[2];int cnt=0,x=0,t=0,win=0;
  For(0,N/2){
    cin >>a[0] >> a[1];
    if(a[0]%2==0 || a[1]%2==0){
      cnt++;t=0;
      For(0,2) if(a[i]%3==0||a[i]%3==1) if(a[i]!=1) t=1;
      x+=t;
    }
  }
  if(cnt&1 || x>0) win=1;
  if(win) cout << "YES" << endl;
  else cout << "NO"  << endl;
}

int main()
{
  //ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> T;
  for(int z=0;z<T;z++) dojob();
  //cin.close();
  return 0;
}
