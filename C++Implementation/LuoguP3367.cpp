#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M;
int p[10010],ran[10010];

void link(int p1, int p2)
{
  if(ran[p1]>ran[p2]) p[p2]=p1;
  else {p[p1]=p2;if(ran[p1]==ran[p2]) ran[p2]++;}
}

int find(int n)
{
  if(n!=p[n]) p[n]=find(p[n]);
  return p[n];
}

int main()
{
  cin >> N >>M;
  For(1,N+1) p[i]=i;
  memset(ran,0,sizeof(ran));
  int z,u,v;
  For(0,M)
  {
    cin >> z >> u >> v;
    if(z==1) link(find(u),find(v));
    if(z==2)
    {
      if(find(u)==find(v)) cout << 'Y' << endl;
      else cout << 'N' << endl;
    }
  }
  return 0;
}
