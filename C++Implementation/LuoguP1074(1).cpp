#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

bool s[10][10],r[10][10],c[10][10];
int ans[10][10];
int block[10];
int p=0,number=0,start=0,startblock=0,startnumber=0;
int x0,y0;

// By using O2, you can pass Luogu. Without O2, only 90.

int calc()
{
  int points=0;
  For(0,8)
  {points+=6*ans[0][i];points+=6*ans[i][8];points+=6*ans[8][i+1];points+=6*ans[i+1][0];}
  For(1,7)
  {points+=7*ans[1][i];points+=7*ans[i][7];points+=7*ans[7][i+1];points+=7*ans[i+1][1];}
  For(2,6)
  {points+=8*ans[2][i];points+=8*ans[i][6];points+=8*ans[6][i+1];points+=8*ans[i+1][2];}
  For(3,5)
  {points+=9*ans[3][i];points+=9*ans[i][5];points+=9*ans[5][i+1];points+=9*ans[i+1][3];}
  points+=10*ans[4][4];
  return points;
}

void sett(int x, int y, int v)
{
  r[x][v]=1;
  c[y][v]=1;
  x=x-x%3+y/3;
  s[x][v]=1;
}
void adsett(int x, int y ,int v)
{
  r[x][v]=0;
  c[y][v]=0;
  x=x-x%3+y/3;
  s[x][v]=0;
}

void Read()
{
  For(0,9)
    for(int j =0;j<9;j++)
      {cin >> ans[i][j];if(ans[i][j]!=0) {sett(i,j,ans[i][j]);number++;block[i-i%3-j/3]++;}}
  p=calc();
  start=p;
  For(0,9)
  if(block[i]>block[startblock])
    startblock=i;
  startnumber=number;
}

void dfs(int x, int y)
{
  //cout << number << ' ';
  if(ans[x][y]>0)
  {
    if(x==x0&&y==y0&&startnumber!=number)
      {p=max(p,calc());return ;}
    if(x==8&&y==8)
      {dfs(0,0);return ;}
    if(y==8)
      {dfs(x+1,0);return ;}
    dfs(x,y+1);return ;
  }
  else
  {
    int num=x-x%3+y/3;
    For(1,10)
    if(!r[x][i]&&!c[y][i]&&!s[num][i])
    {
      ans[x][y]=i;sett(x,y,i);number++;
      if(x==8&&y==8)
        dfs(0,0);
      else if(y==8)
              dfs(x+1,0);
            else
              dfs(x,y+1);
      ans[x][y]=0;adsett(x,y,i);number--;
    }
  }
}

int main()
{
  Read();
  x0=(startblock/3)*3;
  y0=(startblock%3)*3;
  dfs(x0,y0);
  //cout << number << endl;
  if(p!=start)
  cout << p << endl;
  else
  cout << -1 << endl;
  return 0;
}
