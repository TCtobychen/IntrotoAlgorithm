#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(x,y) for(long long int i=x;i<y;i++)
#define ll long long int
using namespace std;

ll N,K,ANS=0,testans=0;

int main()
{
  N=1000,K=1313;
  //cin >> N >> K;
  if(N>K){ ANS+=(N-K)*K;
  ll q=1,end=sqrt(K),ans=0,s,e,t;
  while(q<=end ){
    s=K%(K/q),e=K%(K/(q+1)+1);
    t=(e-s)/q+1;ans=(s+e)*t/2;
    //cout << s <<' '<<e <<' ' << t << endl;
    ANS+=ans;
    q++;
  }
  For(1,K/(end+1)+1) ANS+=K%i;}
  else{
    if(N>K/(sqrt(K)+1)){
      //cout << "HAHHA";
    ll cmp=1,q=max(cmp,K/N),end=sqrt(K),ans=0,s,e,t;
    s=K%N,e=K%(K/(q+1)+1),t=(e-s)/q+1,ans=(s+e)*t/2;ANS+=ans;q++;
    //cout << s <<' '<<e <<' ' << t << endl;
    while(q<=end){
      s=K%(K/q),e=K%(K/(q+1)+1);
      t=(e-s)/q+1;ans=(s+e)*t/2;
      //cout << s <<' '<<e <<' ' << t << endl;
      ANS+=ans;
      q++;
    }}
    ll end=sqrt(K);
    //cout << (K/(end+1)+1) << endl;
    For(1,(int)(K/(end+1)+1)) ANS+=K%i;
  }
  cout << ANS <<endl;
  //For(1,N+1) testans+=K%i;
  //cout << testans <<endl;
  return 0;
}
