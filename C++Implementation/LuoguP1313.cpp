#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(long long int i=x;i<y;i++)
using namespace std;

long long int c[1010][1010];
long long int A,B,K,N,M;
const long long int mod=10007;

long long int ksm(long long int a, long long int n)
{
  long long int ans=1;
  while(n>0){
    if(n&1) ans=ans*a%mod; a=a*a%mod; n>>=1;}
  return ans;
}

long long int com(long long int n, long long int m)
{
  if(n==m || m==0) return c[n][m]=1;
  if(c[n][m]) return c[n][m];
  c[n][m]=(com(n-1,m-1)+com(n-1,m))%mod;
  return c[n][m];
}

int main()
{
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> A >> B >> K >> N >>M;
  cin.close();
  memset(c,0,sizeof(c));
  long long int ANS=ksm(A,N)*ksm(B,M)%mod*com(K,N)%mod;
  if(ANS<0) ANS+=mod; cout << ANS << endl;
  return 0;
}
