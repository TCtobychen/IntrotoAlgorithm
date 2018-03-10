#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int d[2010][2010],m[2010][2010],t[2010][2010],s[2010][2010];
int N,M,a[2010][2010];

void output()
{
  For(0,N) {for(int j=0;j<M;j++) cout << s[i][j] <<' ';  cout << endl;}
}

void output1()
{
  For(0,N) {for(int j=0;j<M;j++) cout << d[i][j] <<' '; cout << endl;}
}
void output2()
{
  For(0,M) {for(int j=1;j<=M-i;j++) cout << t[i][j] <<' '; cout << endl;}
  For(0,M) {for(int j=1;j<=M-i;j++) cout << m[i][j] <<' '; cout << endl;}
  cout << endl;
}
int main()
{
  cin >> N >> M;
  For(0,N) for(int j=0;j<M;j++) {cin >> a[i][j];d[i][j]=1;}
  For(1,min(N,M)) {
    for(int j=0;j<=N-1-i;j++)
      for(int k=0;k<=M-1-i;k++)
      {if(d[j][k]==i&&d[j+1][k+1]==i&&a[j][k]==a[j+1][k+1])
        {if(i%2==1&&a[j][k]!=a[j+i][k]&&a[j][k]!=a[j][k+i]) d[j][k]=i+1;
        if(i%2==0&&a[j][k]==a[j+i][k]&&a[j][k]==a[j][k+i]) d[j][k]=i+1;}
      }
      //output1();cout << endl;
    }
  int ans=0;
  For(0,N) for(int j=0;j<M;j++) ans=max(ans,d[i][j]);
  cout << ans*ans << endl;
  memset(s,-1,sizeof(0));
  memset(t,0,sizeof(t));
  memset(m,0,sizeof(m));
  int ANS=0;
  int start=0,j=0,end;
  while(j<=M-1){
    while(a[0][j]!=a[0][j+1]&&j<M) j++;if(j!=M)j++;end=j;
    for(int k=start;k<end;k++) {for(int z=1;z<=j-k;z++) m[k][z]=z,ANS=max(ANS,m[k][z]);s[0][k]=j-k;}
    start=end;
  }
  //output();cout << endl;
  For(1,N)
  {
    start=0,j=0;
    for(int k=0;k<M;k++) for(int z=1;z<=M-k;z++) t[k][z]=0;
    while(j<=M-1){
      while(a[i][j]!=a[i][j+1]&&j<M) j++;if(j!=M) j++;end=j;
      for(int k=start;k<end;k++) {for(int z=1;z<=j-k;z++) t[k][z]=z,ANS=max(ANS,z);s[i][k]=j-k;}
      start=end;
    }
    //output();cout << endl;
    //output2();
    for(int k=0;k<M;k++) for(int z=1;z<=M-k;z++) if(a[i-1][k]!=a[i][k]) {if(t[k][z]>0) m[k][z]+=t[k][z]; else m[k][z]=0; ANS=max(ANS,m[k][z]);
      //if(ANS==m[k][z]) cout << "!!!" <<i<< k <<' '<<z << ' '<<ANS<<endl;
    }
    else m[k][z]=t[k][z];
  }
  cout << ANS << endl;
  return 0;
}
