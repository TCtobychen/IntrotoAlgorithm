#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
#define ll long long int
using namespace std;

struct Matrix{
  Matrix(ll a,ll b,ll c,ll d) {this->a=a,this->b=b,this->c=c,this->d=d;}
  ll a,b,c,d;
  Matrix& operator*(Matrix& m) {ll a1=m.a*a+m.b*c,b1=m.a*b+m.b*d,c1=m.c*a+m.d*c,d1=m.c*b+m.d*d;
  a=a1,b=b1,c=c1,d=d1;return *this;}
  Matrix& operator%(ll mod) {a%=mod,b%=mod,c%=mod,d%=mod;return *this;}
  friend ostream& operator<<(ostream& out, Matrix m);
};
ostream& operator<<(ostream& out, Matrix m) {out<<m.a <<m.b <<m.c<<m.d<<endl;return out;}

ll N,M,mod=1e8;

ll gcd(ll a, ll b)
{
  ll t;
  while(b>0) t=a%b,a=b,b=t;
  return a;
}

ll Fib(ll n)
{
  if(n==1) return 1;
  if(n==2) return 1;
  // Should be multiplied n-2 times
  Matrix m(1,0,0,1),q(1,1,1,0);n-=2;
  while(n>0){
    //cout << m;
  if(n%2==1) m=m*q%mod;
  n/=2;q=q*q%mod;}
  return (m.a+m.b)%mod;
}

int main()
{
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
   cin >> N >> M;
   cin.close();
   ll d=gcd(N,M);
   cout << Fib(d) << endl;
   return 0;
}
