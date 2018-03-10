#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define END 4020
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

char c1[2010],c2[2010];
int a1[2010],a2[2010];
int ans[END],temp[END];
int carry=0,len1,len2;

void dojob(int n)
{
  carry=0;
  memset(temp,0,sizeof(temp));
  int index=a2[len2-1-n],ANS,last=END-1-n;
  for(int j=len1-1;j>=0;j--)
  {
    ANS=a1[j]*index+carry;
    temp[last--]=ANS%10;
    carry=ANS/10;
  }
  temp[last]=carry;
  carry=0;
  for(int j=END-1;j>=last-1;j--)
  {
    ans[j]=ans[j]+temp[j]+carry;
    if(ans[j]>9) ans[j]-=10,carry=1;
    else carry=0;
  }
  //cout << ans[last] << ans[last+1] << endl;
}

int main()
{
  memset(c1,0,sizeof(c1));
  memset(c2,0,sizeof(c2));
  memset(a1,0,sizeof(a1));
  memset(a2,0,sizeof(a2));
  memset(ans,0,sizeof(ans));
  //memset(temp,0,sizeof(temp));
  scanf("%s",c1);scanf("%s",c2);
  len1=strlen(c1);len2=strlen(c2);
  For(0,len1) a1[len1-1-i]=c1[len1-1-i]-'0';
  For(0,len2) a2[len2-1-i]=c2[len2-1-i]-'0';
  For(0,len2) {dojob(i);}
  int k=0;
  while(ans[k]==0 && k<END) k++;
  For(k,END) cout << ans[i];
  if(k==END) cout << 0;
  cout << endl;
  return 0;
}
