#include <iostream>
#include <queue>
#include <vector>
#define INF 10000
using namespace std;

typedef pair<int ,int* > pint;
int E[100][100];
int d[100];
int N,M;

struct cmp {
  bool operator() (const pint p1, const pint p2) const{
    return *(p1.second) > *(p2.second);
  }
};

priority_queue<pint, vector<pint>,cmp> q;

void Read()
{
  cin >> N >> M;
  for(int i =0;i<N;i++)
    d[i]=INF;
  d[0]=0;
  for(int i =0;i<N;i++)
    for(int j=0;j<N;j++)
    {
      if(i!=j)
        E[i][j]=INF;
      else
        E[i][j]=0;
    }
  for(int i =0;i<M;i++)
  {
    int v1,v2,e;
    cin >> v1 >> v2 >> e;
    E[v1][v2]=e;
  }
}

void Relax(int v)
{
  for(int i = 0;i<N;i++)
  {
    d[i]=(d[i]>d[v]+E[v][i])?(d[v]+E[v][i]):d[i];
  }
}

void Dijkstra(int E[100][100])
{
  for(int i = 0;i<N;i++)
    q.push(make_pair(i,&d[i]));
  for(int i =0;i<N;i++)
  {
    pint pt=q.top();
    cout << pt.first << "HERE" << endl;
    Relax(pt.first);
    q.pop();
  }
}

int main()
{
  priority_queue<pint>q;
  Read();
  Dijkstra(E);
  for(int i = 0;i<N;i++)
  cout << d[i] << endl;
  cout << "END!" << endl;
}
