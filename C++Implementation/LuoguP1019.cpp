#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

string s[25];
stack<int> temp;
int c[25][25];
queue<int> nex[25];
int countt[25];
int ans=0,N;

void dojob(string ss, int n)
{
  For(0,n+1)
  {
    int ok=0,j;
    for(j =1;j<ss.length()&&j<s[i].length();j++)
    {
      ok=1;
      for(int k = 0;k<j;k++)
        if(ss[ss.length()-j+k]!=s[i][k])
          {ok=0;break;}
      if(ok)
      break;
    }
    if(ok)
    {
      c[n][i]=j;
      nex[n].push(i);
    }
  }
  For(0,n)
  {
    int ok=0,j;
    for(j =1;j<s[i].length()&&j<ss.length();j++)
    {
      ok=1;
      for(int k = 0;k<j;k++)
        if(s[i][s[i].length()-j+k]!=ss[k])
          {ok=0;break;}
      if(ok)
      break;
    }
    if(ok)
    {
      c[i][n]=j;
      nex[i].push(n);
    }
  }
}

void initial()
{
  For(0,N)
  countt[i]=2;
  while(!temp.empty())
  temp.pop();
}

void output()
{
  stack<int > z;
  int k;
  while(!temp.empty())
    {
      k=temp.top();
      temp.pop();
      z.push(k);
    }
  while(!z.empty())
  {
    k=z.top();
    cout << s[k] <<' ';
    temp.push(k);
    z.pop();
  }
}

int dfs(int n, int cover)
{
  //cout <<"ROUND" << endl;
  if(countt[n]<=0)
    {return cover;}
  countt[n]--;
  temp.push(n);
  //output();
  int len=max(cover,(int)s[n].length()),rec;
  int comp=len;
  //cout <<"111" << endl;
  //cout <<"size" << nex[n].size() << endl;
  For(0,nex[n].size())
  {
    int t=nex[n].front();
    len=max(len,(int)(s[n].length()+dfs(t,c[n][t])-c[n][t]));
    //output();
    nex[n].pop();
    nex[n].push(t);
  }
  countt[n]++;
  if(len==comp)
  //output();
  temp.pop();
  return len;
}

void outputq()
{
  for(int j=0;j<N;j++)
  {For(0,nex[j].size())
  {
    int t=nex[j].front();
    cout << t <<' ';
    nex[j].pop();
    nex[j].push(t);
  }
  cout << endl;}
}

int main()
{
  cin >> N;
  memset(c,0,sizeof(c));
  For(0,N)
  {
    cin >> s[i];
    dojob(s[i],i);
  }
  //outputq();
  //cout <<"!!!!"<<endl;
  char c;
  cin >> c;
  For(0,N)
  if(c==s[i][0])
    {
      initial();
      //cout << i << endl;
      ans=max(ans,dfs(i,0));
    }
  /*string s1="tact",s2="ta";
  dojob(s1,1);
  dojob(s2,2);
  cout << (s1.find(s2)==s1.npos);
  cout << endl;*/
  //cout << nex[1].size() << endl;
  cout <<ans << endl;
  return 0;
}
