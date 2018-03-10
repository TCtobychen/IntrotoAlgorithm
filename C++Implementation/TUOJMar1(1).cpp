#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,sx,sy,tx,ty,a[100][100],vis[100][100],ok=0;
int s1[4]={-1,1,0,0},s2[4]={0,0,-1,1};

void output(){
  cout << N <<' '<<M <<' '<<sx+1 <<' '<< sy+1 <<' '<< tx+1 <<' '<<ty+1<<endl;
  For(0,N) {for(int j=0;j<M;j++) switch(a[i][j]){
    case 0: cout << '.';break;
    case 1 :cout << 'w';break;
    case 2: cout << 's';break;
    case 3 : cout << 'a' ;break;
    case 4:cout << 'd' ;break;
  } cout << endl;}
  ok=1;
}

void dfs(int x, int y)
{
  if(!ok){
  //cout << x <<' '<<y <<endl;
  if(x==tx&&y==ty) output();
  if(a[x][y]!=0)
  switch(a[x][y]){
    case 1 :if(x>0&&!vis[x-1][y]) {vis[x-1][y]=1;dfs(x-1,y);vis[x-1][y]=0;}break;
    case 2:if(x<N-1&&!vis[x+1][y]) {vis[x+1][y]=1;dfs(x+1,y);vis[x+1][y]=0;}break;
    case 3:if(y>0&&!vis[x][y-1]) {vis[x][y-1]=1;dfs(x,y-1);vis[x][y-1]=0;}break;
    case 4:if(y<M-1&&!vis[x][y+1]) {vis[x][y+1]=1;dfs(x,y+1);vis[x][y+1]=0;}break;
  }
  if(a[x][y]==0)
  For(0,4){
    //cout <<"!!" <<x+s1[i] <<' '<< y+s2[i]<< endl;
    if(0<=x+s1[i]&&x+s1[i]<N&&0<=y+s2[i]&&y+s2[i]<M&&!vis[x+s1[i]][y+s2[i]]){
      //cout << "test" << x+s1[i] << ' '<< y+s2[i]<<endl;
      //cout <<"!!" <<x+s1[i] <<' '<< y+s2[i]<< endl;
      a[x][y]=i+1;
      vis[x+s1[i]][y+s2[i]]=1;
      dfs(x+s1[i],y+s2[i]);
      vis[x+s1[i]][y+s2[i]]=0;
      a[x][y]=0;
    }
  }}
}

int main()
{
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test1.in");
  cin >> N >> M >> sx >>sy >>tx>> ty;
  sx--;sy--;tx--;ty--;
  char c;int t;
  For(0,N) for(int j=0;j<M;j++) {cin >> c;
    switch (c) {
      case 'w':t=1;break;
      case 's' : t=2;break;
      case 'a' : t=3;break;
      case 'd' : t=4;break;
      case '.' : t=0;break;
    }
    a[i][j]=t;}
  cin.close();
  memset(vis,0,sizeof(vis));
  vis[sx][sy]=1;
  dfs(sx,sy);
  return 0;
}
