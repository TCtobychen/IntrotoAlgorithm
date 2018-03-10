#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

char c1[510],c2[510];
int a1[510],a2[510],ans[510];
int carry=0;

void dojob(int n)
{
  int t=a1[n]+a2[n]+carry;
  if(t>9) t-=10,carry=1;
  else carry=0;
  ans[n]=t;
}

int main()
{
  memset(c1,0,sizeof(c1));
  memset(c2,0,sizeof(c2));
  memset(ans,0,sizeof(ans));
  memset(a1,0,sizeof(a1));
  memset(a2,0,sizeof(a2));
  //gets(c1);gets(c2);
  scanf("%s",c1);scanf("%s",c2);
  int len1=strlen(c1), len2=strlen(c2);
  int l=max(len1,len2);
  For(0,len1) a1[l-i]=c1[len1-i-1]-'0';
  For(0,len2) a2[l-i]=c2[len2-i-1]-'0';
  for(int j=l;j>=0;j--) dojob(j);
  if(ans[0]>0) cout << ans[0];
  For(1,l+1) cout << ans[i];
  cout << endl;
  return 0;
}
