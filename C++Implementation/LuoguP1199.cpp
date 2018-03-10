#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,vis[510];
struct S{int score,u,v;}a[250010];

bool comparison(S a1, S a2)
{return a1.score>a2.score;}

int main()
{
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  int num=0,ok=0,cnt=0;
  memset(vis,0,sizeof(vis));
  cin >> N;
  For(0,N) for(int j=i+1;j<N;j++) {cin >> a[num].score;a[num].u=i,a[num].v=j;num++;}
  cin.close();
  sort(a,a+num,comparison);
  cout << 1 << endl;
  while(!ok){
    int s=a[cnt].score,u=a[cnt].u,v=a[cnt].v;
    if(vis[u] || vis[v]) {ok=1;cout << s << endl;}
    else vis[u]=vis[v]=1;cnt++;
  }
  return 0;
}
