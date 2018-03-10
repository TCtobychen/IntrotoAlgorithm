#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

char c1[10010],c2[10010];
int a1[10010],a2[10010],ans[10010];
int carry=0;

void dojob(int n)
{
  //cout << n << a1[n] << a2[n] << carry << endl;
  ans[n]=a1[n]-a2[n]-carry;
  //cout << ans[n] << endl;
  if(ans[n]<0) ans[n]+=10,carry=1;
  else carry=0;
}

int main()
{
  int gt=0;
  memset(c1,0,sizeof(c1));
  memset(c2,0,sizeof(c2));
  memset(a1,0,sizeof(a1));
  memset(a2,0,sizeof(a2));
  memset(ans,0,sizeof(ans));
  scanf("%s",c1);scanf("%s",c2);
  int len1=strlen(c1),len2=strlen(c2);
  int l=max(len1,len2);
  if(len1==len2) {For(0,len1) {if(c1[i]>c2[i]) {gt=1;break;} if(c1[i]<c2[i]) {gt=2;break;}}}
  if(len1>len2) gt=1; if(len1<len2) gt=2;
  if(gt==1){
  For(0,len1) a1[l-i-1]=c1[len1-1-i]-'0';
  For(0,len2) a2[l-i-1]=c2[len2-1-i]-'0';}
  if(gt==2){
    For(0,len2) a1[l-i-1]=c2[len2-1-i]-'0';
    For(0,len1) a2[l-i-1]=c1[len1-1-i]-'0';}
  if(gt==0) {cout << 0 << endl;return 0;}
  for(int j=l-1;j>=0;j--) dojob(j);
  if(gt==2) cout << '-' ;
  int j=0;
  while(ans[j]==0) j++;
  For(j,l) cout << ans[i];
  cout << endl;
  return 0;
}
