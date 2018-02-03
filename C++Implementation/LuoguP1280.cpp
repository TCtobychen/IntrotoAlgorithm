#include <iostream>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
#define INF 100000;
using namespace std;


// It fails.

int d[10010][10010][2];  // d[tasks][time]
int N,K;
pair<int, int > endd[10010];

bool comparison(pair<int, int > p1, pair<int ,int > p2)
{
  return p1.first < p2.first;
}

int dojob(int k, int t, int l)
{
  if(d[k][t][l]!=-1)
    {cout << k << ' '<< t <<' '<<l<<' '<<d[k][t][l]<< endl;return d[k][t][l];}
  if(t<=endd[k].second)
    {d[k][t][l]=dojob(k-1,t,l);cout << k << ' '<< t <<' '<<l<<' '<<d[k][t][l]<< endl;return d[k][t][l];}
  if(t>endd[k].second && t<endd[k].first)
  {
    d[k][t][1]=max(dojob(k-1,t,1),dojob(k-1,endd[k].second,0));
    d[k][t][0]=dojob(k-1,t,0);
    cout << k << ' '<< t <<' '<<l<<' '<<d[k][t][l]<< endl;return d[k][t][l];
  }
  if(t>=endd[k].first)
  {
    d[k][t][1]=-INF;
    d[k][t][0]=max(dojob(k-1,t,0),dojob(k-1,endd[k].second,0)+t-endd[k].first);
    cout << k << ' '<< t <<' '<<l<<' '<<d[k][t][l]<< endl;return d[k][t][l];
  }
}

int main()
{
  cin >> N >> K;
  int s,e;
  For(0,K)
  {cin >> s >> e;endd[i+1].first=s+e-1;endd[i+1].second=s;}
  sort(endd+1,endd+1+K,comparison);
  memset(d,-1,sizeof(d));
  For(0,N+1)
  {d[0][i][0]=i;d[0][i][1]=-INF;}
  For(0,K+1)
  d[i][0][0]=0;
  cout << dojob(K,N,0) << endl; // dojob(k,t) equals to the max leisure time got before(included) t considering first k tasks.
  return 0 ;
}
