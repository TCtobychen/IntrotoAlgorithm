#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define pr pair<int,int>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;
pr cst(2,2);

struct State{
  State(int b[3][3]=NULL, pr pp=cst) {For(0,3) for(int j=0;j<3;j++) a[i][j]=b[i][j];p.first=pp.first,p.second=pp.second;};
  int a[3][3];pr p;
};
queue<State> q;

State ans[1000];
long long ANS=0;
int vis[1000];
int s1[4]={1,0,-1,0},s2[4]={0,1,0,-1};

int h(int c[3][3]){
  int ans1=0,ans2=0;
  For(0,3) ans1=ans1*10+c[0][i];ans1+=ans1*10+c[1][0];
  For(1,3) ans2=ans2*10+c[1][i];
  For(0,3) ans2=ans2*10+c[0][i];
  return (ans1+ans2);
}

void sw(int t[3][3], int x, int y, int xx ,int yy){
  int temp;temp=t[x][y];t[x][y]=t[xx][yy];t[xx][yy]=temp;return ;
}

void dojob(State s){
  int t[3][3];int x,y,xx,yy;
  For(0,3) for(int j=0;j<3;j++) t[i][j]=s.a[i][j];
  x=s.p.first,y=s.p.second;
  For(0,4){
    xx=x+s1[i],yy=y+s2[i];
    if(0<=xx&&xx<3&&0<=yy&&yy<3){
      sw(t,x,y,xx,yy);
      int ind=h(t);
      if(vis[ind]==0){pr tt(xx,yy);State ss(t,tt);q.push(ss);vis[ind]=1;if(xx==2&&yy==2) ANS++;}
      sw(t,x,y,xx,yy);
    }
  }
}

int main()
{
  int start[3][3];
  int num=1;
  memset(vis,0,sizeof(vis));
  For(0,3) for(int j=0;j<3;j++) start[i][j]=num,num++;
  pr ps(2,2);
  State s0(start,ps);
  q.push(s0);
  while(!q.empty()){
    State st=q.front();
    dojob(st);
    q.pop();
  }
  cout << ANS << endl;
  return 0;
}
