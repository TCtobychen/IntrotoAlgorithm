#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define random(a,b) (rand()%(b-a+1)+a)
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

pair<int,int> a[1000];
int N=500;
int x=1,y=2,z=3;

int getresult(pair<int,int> p)
{
  int ans=p.first*x+p.second*y;
  ans=10000/(100*abs(ans-z)+abs(p.first+p.second-2)+100)+1;
  return ans;
}

void Initial()
{
  For(0,500) a[i].first=random(100,300),a[i].second=random(100,300);
}

bool comparison(pair<int,int> p1, pair<int,int> p2)
{
  return getresult(p1)>getresult(p2);
}

void Coitus()
{
  For(0,500){
    pair<int,int> p0;
    int a1=getresult(a[i]),a2=getresult(a[i+1]);
    p0.first=a1*a[i].first/(a1+a2)+a2*a[i+1].first/(a1+a2);
    p0.second=a1*a[i].second/(a1+a2)+a2*a[i+1].second/(a1+a2);
    a[i+500]=p0;
  }
}

void Mutate()
{
  For(0,4)
  {
    int index=random(0,500);
    a[index].first=random(-1000,1000),a[index].second=random(-1000,1000);
  }
}

void Kill(){
  sort(a,a+1000,comparison);
}

int main()
{
  srand((unsigned(time(NULL))));
  Initial();
  For(0,500){
    Mutate();
    Coitus();
    Kill();
  }
  For(0,50) cout << a[i].first << ' ' << a[i].second << ' '<<getresult(a[i])<<endl;
  return 0;
}
