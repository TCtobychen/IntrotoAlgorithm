#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
#define ll long long int
using namespace std;

int N,cnt=0,num=1,vis=0,cntt=0;

void dojob(ll a, ll b)
{
  cnt=0;
  if(a<b) {dojob(b,a);return;}
  ll t;
  while(a%b!=0){
    if(a>2*b) {break;}
    t=a%b,a=b,b=t;cnt=1-cnt;
  }
  if(cnt) cout << "Ollie wins" << endl;
  else cout << "Stan wins" << endl;
}

int main()
{
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N;
  ll a,b;
  For(0,N) {cin >> a >> b;dojob(a,b);}
  cin.close();
  return 0;
}
