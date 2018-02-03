#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

bool s[10][10],r[10][10],c[10][10];
int ans[10][10];
int left[10][10];
int block[10];
int p=0,number=0,start=0,startblock=0,startnumber=0;
int x0,y0;
pair<pair<int ,int>, int > node[90];
stack<pair<int, int> > waiting;

void output()
{
  For(0,9)
    {for(int j=0;j<9;j++)
      cout << ans[i][j] <<' ';cout << endl;}
}

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

bool comparison(pair<pair<int ,int>, int > node1, pair<pair<int ,int>, int > node2)
{
  return node1.second < node2.second;
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
  memset(r,0,sizeof(r));
  memset(c,0,sizeof(c));
  memset(s,0,sizeof(s));
  For(0,9)
    for(int j =0;j<9;j++)
      {
        cin >> ans[i][j];
        if(ans[i][j]!=0) {sett(i,j,ans[i][j]);number++;block[i-i%3+j/3]++;}}
  p=calc();
  start=p;
  For(0,9)
  if(block[i]>block[startblock])
    startblock=i;
  startnumber=number;
}

void dfs(int x, int y)
{
    For(1,10)
    if(!r[x][i]&&!c[y][i]&&!s[x-x%3+y/3][i])
    {
      ans[x][y]=i;sett(x,y,i);number++;
      if(waiting.empty())
      {
        p=max(p,calc());
        output();
      }
      else
      {
        pair<int , int> tt;
        tt=waiting.top();
        waiting.pop();
        dfs(tt.first, tt.second);
        waiting.push(tt);
      }
      ans[x][y]=0;adsett(x,y,i);number--;
    }
}

void setleft()
{
  int k =0;
  For(0,81)
  node[i].second=-1;
  //cout << "TEST" << endl;
  For(0,9)
    for(int j=0;j<9;j++)
    {
      if(ans[i][j]==0){
      node[k].second=0;
      node[k].first.first=i;node[k].first.second=j;
      int b=i-i%3+j/3;
      for(int z=1;z<10;z++)
      if(r[i][z]||c[j][z]||s[b][z])
        node[k].second++;}
      k++;
    }
  sort(node,node+k,comparison);
  int n=0;
  while(node[n].second<0)
    n++;
  For(n,k)
    {waiting.push(node[i].first);}
}


int main()
{
  Read();
  /*For(1,10)
  cout << r[6][i] << c[3][i] << s[7][i] << endl;
  cout << "!!!!!!!";*/
  //x0=(startblock/3)*3;
  //y0=(startblock%3)*3;
  /*for(int i =x0+2;i>=x0;i--)
    for(int j = y0+2;j>=y0;j--)
      if(ans[i][j])
        {x0=i;y0=j;}*/
  setleft();
  pair<int, int> ss;
  ss=waiting.top();
  waiting.pop();
  x0=ss.first;y0=ss.second;
  //cout << x0 << y0 <<"~!!" <<endl;
  dfs(x0,y0);
  //cout << number << endl;
  /*if(p!=start)
  cout << p << endl;
  else
  cout << -1 << endl;*/
  return 0;
}
