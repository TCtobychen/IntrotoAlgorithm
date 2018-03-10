#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int phi[40010],isprime[40010],primesize=0,prime[40010];
int N;

void getphi(int n)
{
  For(0,n) isprime[i]=1;
  primesize=0;isprime[1]=0;
  For(2,n)
  {
    if(isprime[i]==1) prime[primesize++]=i,phi[i]=i-1;
    for(int j =0;j<primesize && i*prime[j]<n;j++)
    {
      isprime[i*prime[j]]=0;
      if(i%prime[j]==0) {phi[i*prime[j]]=phi[i]*prime[j];break;}
      phi[i*prime[j]]=phi[i]*(prime[j]-1);
    }
  }
}

int main()
{
  cin >> N;
  getphi(N);
  //For(0,N) cout << phi[i]<< ' '<<prime[i] << ' ';
  //cout << endl;
  if(N!=1){
  int ans=0;
  For(2,N) ans+=2*phi[i];
  ans+=3;
  cout << ans << endl;}
  else
  cout << 0 << endl;
  return 0;
}
