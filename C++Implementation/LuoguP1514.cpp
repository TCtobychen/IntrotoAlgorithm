#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <set>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;
typedef pair<int,int> pr;

int h[510][510],vis1[510],vis[510][510],c1[4]={1,0,-1,0},c2[4]={0,1,0,-1};
int imp[510],p[510],ind[510];
int N,M,now,cnt=0;
queue<pr > q;
struct val{
  int start,end;
};
val v[510],w[250];

void bfs(pr t)
{
  int x=t.first, y=t.second,x0,y0;
  if(x==0) p[y]=now;
  if(x==N-1) {v[cnt].start=min(v[cnt].start,y),v[cnt].end=max(v[cnt].end,y);imp[y]=1;}
  For(0,4){
    x0=x+c1[i];y0=y+c2[i];
    if(x0>=0&&x0<N&&y0>=0&&y0<M&&h[x0][y0]<h[x][y]&&!vis[x0][y0]) {vis[x0][y0]=1; pr p1(x0,y0);q.push(p1);}
  }
}

void output1()
{
  For(0,N) {for(int j=0;j<M;j++) cout << vis[i][j] <<' '; cout << endl;}
}

void dojob()
{
  ind[now]=cnt;
  memset(vis,0,sizeof(vis));
  v[cnt].start=M-1;v[cnt].end=0;
  while(!q.empty()) q.pop();
  pr p0(0,now);
  q.push(p0);vis[0][now]=1;
  while(!q.empty()) {pr tp=q.front();bfs(tp);q.pop();}
  //For(v[cnt].start,v[cnt].end+1) imp[i]=1;
  cnt++;
  //output1();
  //cout << endl;
}

bool comparison(val v1, val v2)
{
  return v1.end>v2.end;
}

int find(int n)
{
  if(n!=p[n]) p[n]=find(p[n]);
  return p[n];
}

int main()
{
  //ifstream cin("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  //if(!cin) cout << "ERROR" << endl;
  cin >> N >> M;
  For(0,N) for(int j=0;j<M;j++) cin>>h[i][j];
  //cin.close();
  //fclose(stdin);
  memset(vis,0,sizeof(vis));
  memset(vis1,0,sizeof(vis1));
  For(0,M) p[i]=i;
  if(h[0][0]<h[0][1]) vis1[0]=1;
  if(h[0][M-1]<h[0][M-2]) vis1[M-1]=1;
  For(1,M-1) if(h[0][i]<h[0][i-1] || h[0][i]<h[0][i+1]) vis1[i]=1;
  memset(imp,-1,sizeof(imp));
  for(now=0;now<M;now++) if(vis1[now]==0) {dojob();}
  // Here all pnt values should have been set
  int ok=1,num=0;
  For(0,M) if(imp[i]==-1) ok=0,num++;
  if(!ok) {cout << ok << endl << num << endl;return 0;}
  cout << 1 << endl;
  set<int> s;int c=0;
  For(0,M) if(s.count(find(i))==0) {w[c].start=v[ind[find(i)]].start;w[c++].end=v[ind[find(i)]].end;s.insert(find(i));}
  sort(w,w+c,comparison);
  int last=0;num=0;
  while(last<=M-1) For(0,c) if(w[i].start<=last) {last=w[i].end+1;num++;break;}
  cout << num << endl;
  return 0;
}
