#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int isprime[10000010],primesize=0,prime[1000010];
int N,M;

void getlist()
{
  For(2,N+1) isprime[i]=1;
  memset(prime,0,sizeof(prime));
  isprime[1]=0;
  For(2,N+1)
  {
    if(isprime[i]==1) prime[primesize++]=i;
    for(int j=0;j<primesize && i*prime[j] <=N;j++)
    {
      isprime[i*prime[j]]=0;
      if(i%prime[j]==0) break;
    }
  }
}


int main()
{
  cin >> N >> M;
  getlist();
  int t;
  For(0,M) {cin >> t;if(isprime[t]==1) cout << "Yes" << endl;else cout << "No" << endl;}
  return 0;
}
