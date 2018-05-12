#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,cnt=0,e[1000][1000],deg[1000],ans[1000],pos=0;

void add(char c1, char c2){
  int a,b;
  if(c1>='a'&&c1<='z') a=c1-'a'+27;
  if(c1>='A'&&c1<='Z') a=c1-'A'+1;
  if(c2>='a'&&c2<='z') b=c2-'a'+27;
  if(c2>='A'&&c2<='Z') b=c2-'A'+1;
  e[a][b]=e[b][a]=1;
  deg[a]++;deg[b]++;
 }

void print(int k){
  char c;
  if(1<=k&&k<=26) c=k+'A'-1;
  else c=k+'a'-27;
  cout << c;
}

void dfs(int n){
  int ok=0;
  for(int i=1;i<=52;i++){
    if(e[n][i]==1){
      ok=1;
      e[n][i]=e[i][n]=0;
      dfs(i);
      //print(n);
    }
  }
  ans[++pos]=n;
}

int main()
{
  memset(e,0,sizeof(e));
  memset(deg,0,sizeof(deg));
  string s;
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N;
  For(0,N) {cin >> s;add(s[0],s[1]);}
  cin.close();
  int num=0,start=10000;
  For(1,53) if(deg[i]%2==1) {num++;start=min(i,start);}
  if(num==1||num>2) cout << "No Solution" << endl;
  else {if(num==0) For(1,53) if(deg[i]>0) start=min(i,start);
  dfs(start);}
  for(int i=pos;i>=1;i--) print(ans[i]);
  return 0;
}
