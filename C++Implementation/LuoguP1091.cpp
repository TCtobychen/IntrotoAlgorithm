#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int d[110][110];
int a[110];
int N;
//cout << i << ' ' << j << ' '<< d[i][j]<< endl;
int dojob(int * l1, int * l2, int i, int j)
{
  if(d[i][j]>=0)
    {return d[i][j];}
  if(l1[i-1]==l2[j-1])
    {d[i][j]=dojob(l1,l2,i-1,j-1)+1;return d[i][j];}
  else
    {d[i][j]=max(dojob(l1,l2,i-1,j),dojob(l1,l2,i,j-1));return d[i][j];}
}

int lins(int *l, int start, int end)
{
  int l1[110],l2[110];
  set<int > s;
  int t,num=0;
  For(start,end)
  {
    t=l[i];
    if(s.count(t)==0)
      {l1[num]=l2[num]=t;num++;}
    s.insert(t);
  }
  sort(l2,l2+num);
  memset(d,-1,sizeof(d));
  For(0,num)
  d[0][i]=d[i][0]=0;
  return dojob(l1,l2,num,num);
}

bool comparison(int k, int j)
{return k>j;}

int lds(int *l, int start, int end)
{
  int l1[110],l2[110];
  set<int > s;
  int t,num=0;
  For(start,end)
  {
    t=l[i];
    if(s.count(t)==0)
      {l1[num]=l2[num]=t;num++;}
    s.insert(t);
  }
  sort(l2,l2+num,comparison);
  memset(d,-1,sizeof(d));
  For(0,num)
  d[0][i]=d[i][0]=0;
  return dojob(l1,l2,num,num);
}

int main()
{
  cin >> N;
  int t,num=0;
  For(0,N)
  cin >> a[i];
  int ans=0;
  cout << lins(a,0,1) << endl;
  cout << lds(a,2,3) << endl;
  For(0,N)
  ans=max(ans,lins(a,0,i+1)+lds(a,i,N)-1);
  cout << (N-ans) << endl;
  return 0;
}
