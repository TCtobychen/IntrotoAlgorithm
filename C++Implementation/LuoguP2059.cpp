#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,c[55],cnt[55];
double p[55],temp[55];

void dojob(int k,int n){ // k+1 is the player for the next round
  double p0=(double)cnt[k]/M;
  //cout << p0 << "!!!" << endl;
  if(p0!=0){
    For(1,n-k+1) temp[k+i]+=p0*p[i];
    For(n-k+1,n) temp[(k+i)%n]+=p0*p[i];
  }
}

void brush(int n)
{
  memset(cnt,0,sizeof(cnt));
  memset(temp,0,sizeof(temp));
  For(1,M+1) cnt[c[i]%n]++;
  //For(0,n) cout << cnt[i] << ' ';cout << endl;
  For(1,n) dojob(i,n);
  if(cnt[0]!=0){
    double pp=(double)cnt[0]/M;
    For(1,n) temp[i]+=pp*p[i];
  }
  For(0,n+1) p[i]=temp[i];
}

int main()
{
  //ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N >> M;
  For(0,M) cin >> c[i+1];
  //cin.close();
  memset(p,0,sizeof(p));
  p[1]=1;
  For(2,N+1) brush(i);
  For(1,N+1) {printf("%.2f",p[i]*100);cout << "% ";}
  cout << endl;
  return 0;
}
