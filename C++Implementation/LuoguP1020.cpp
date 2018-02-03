#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int a[100010],b[100010];

int dojob(int *l1, int *l2, int start,int end1, int end2, int[100010][100010] d)
{
  if(d[end1][end2]>=0)
    return d[end1][end2];
  if(l1[end1]==l2[end2])
    {d[end1][end2]=dojob(l1,l2,start,end1-1,end2-1,d)+1;return d[end1][end2];}
  if(l1[end1]!=l2[end2])
    {d[end1][end2]=max(dojob(l1,l2,start,end1-1,end2,d),dojob(l1,l2,start,end1,end2-1,d));return d[end1][end2];}
}

int lcs(int * l1, int * l2, int start, int end, int *ans)
{
  int d[100010][100010];
  For(start-1,end)
  d[i][start-1]=d[start-1][i]=0;
  d[end][end]=dojob(l1,l2,start,end,end,d);
  stack<int> s;
  int end1=end2=end;
  while(d[end1][end2]>0)
  {
    if(l1[end1]==l2[end2])
      {s.push();end1--;end2--;}
    else
    {
      if(d[end1][end2]==d[end1-1][end2])
        {end1--;continue;}
      else
        {end2--;continue;}
    }
  }
  int num=0;
  while(!s.empty())
  {int t=s.top();s.pop();ans[num]=t;num++;}
  num--;
  return num;
}

int main()
{
  /*int N=0;
  while(cin >> a[N])
  N++;*/
  int c[3]={1,2,3},d[3]={1,4,3},e[3]={0};
  int number=lcs(c,d,0,2,e);
  For(0,number)
  cout << e[i] << endl;
  return 0;
}
