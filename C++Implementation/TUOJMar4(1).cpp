#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,a[20][20],vis[20][20],ans[20][20],cnt=0;
long long int ANS=0;
int s1[2]={0,1},s2[2]={1,0};

void dfs(int x, int y){
  cout << x << ' '<<y <<' '<<cnt<< endl;
  For(0,2){
    int xx=x+s1[i],yy=y+s2[i];
    if(xx<N&&yy<M&&a[xx][yy]==0 && !vis[xx][yy]){
      ANS++;
      cout << x << ' '<<y <<' '<<cnt<<' '<<i<< endl;
        vis[x][y]=vis[xx][yy]=1;cnt-=2;
      For(x,N) for(int j=0;j<M;j++) if(a[i][j]==0&&!vis[i][j]) dfs(i,j);
      vis[x][y]=vis[xx][yy]=0;cnt+=2;
    }
  }
}

void dojob(int x, int y)
{
  cout << x << y << endl;
  ANS=0;
  int tx,ty;
  memset(vis,0,sizeof(vis));
  if(a[x][y]==1) return ;
  a[x][y]=1;
  for(int i=N-1;i>=0;i--) for(int j=M-1;j>=0;j--) if(a[i][j]==0) tx=i,ty=j;
  dfs(tx,ty);
  ans[x][y]=ANS;
  ANS++;
  a[x][y]=0;
}
void output(){
  For(0,N) {for(int j=0;j<M;j++) cout << ans[i][j]<<' '; cout << endl;}
}


int main()
{
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N>> M;
  For(0,N) for(int j=0;j<M;j++) {cin >> a[i][j];if(a[i][j]==0) cnt++;}
  cin.close();
  cnt--;
  memset(ans,0,sizeof(ans));
  For(0,N) for(int j=0;j<M;j++) dojob(i,j);
  output();
  return 0;
}
