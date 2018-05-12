#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

const int Len=1e5+10;
const int Mod=1e9+7;
const int L=1e6+10;
int N,K,cnt=1,min=0;
int ans[Len],a[L];

void ins(int m){
  //cout << "INS  " << m << endl;
  if(m<=ans[K-1]) return ;
  ans[K-1]=m;
  int temp=K-1,t;
  for(temp=K-2;ans[temp]<m&&temp>=0;temp--) 1;
  temp++;
  for(int i=K-1;i>temp;i--) ans[i]=ans[i-1];
  ans[temp]=m;
  cnt++;
}

void copy(int k){
  a[k+1]=1;
  for(int i=k;i>=1;i--) {a[i]+=a[i-1];a[i]%=Mod;ins(a[i]);}
  a[0]=1;
}

int main()
{
  ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> K;
  cin.close();
  memset(ans,0,sizeof(ans));
  ans[0]=1;
  a[0]=1;
  For(0,N) copy(i);
  //For(0,K) cout << ans[i] << endl;
  //For(0,N+1) cout << a[i] <<' '; cout << endl;
  int sum=0;
  For(0,K) {sum+=ans[i];sum%=Mod;}
  if(K>cnt) sum+=K-cnt;
  cout << sum << endl;
}
