#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> E;
queue<int> P[100];
int C[100][100];
int e[100];
int h[100];
int A[100][100];
int N,M,S,T;

void Read()
{
  int v1,v2,e;
  cin >> N >> M >> S >> T;
  memset(A,-1,sizeof(A));
  memset(C,-1,sizeof(E));
  for(int i =0;i<M;i++)
  {
    cin >> v1 >> v2 >> e;
    C[v1][v2]=e;
    A[v1][v2]=e;
    A[v2][v1]=0;
  }
}

void Initial() // Initialize the first preflow, initialize the queue E,P, initialize heights.
{
  memset(h,0,sizeof(h));
  h[S]=N;
  for(int i=0;i<N;i++)
    if(C[S][i]>0)
    {
      A[S][i]=0;
      A[i][S]=C[S][i];
      e[i]=C[S][i];
      E.push(i);
    }
}

void del(int u , int v)
{
  int start=P[u].front();
  if(start==v)
    {P[u].pop();return;}
  P[u].pop();
  P[u].push(start);
  while(P[u].front()!=start)
  {
    int t=P[u].front();
    if(t!=v)
    {
      P[u].pop();
      P[u].push(t);
    }
    if(t==v)
    {
      P[u].pop();
      return;
    }
  }
  return ;
}

int Push(int u)
{
  if(P[u].empty())
    return 0;
  int v = P[u].front();
  int flowchange = min(e[u],A[u][v]);
  e[u]-=flowchange;
  e[v]+=flowchange;
  A[u][v]-=flowchange;
  A[v][u]+=flowchange;
  if(flowchange==A[u][v])
    del(u,v);
  P[u].pop();
  if(v!=T&&v!=S)
    E.push(v);
  return 1;
}

void Relabel(int u) // O(V^2) time
{
  int v = 0;
  for(int i = 0;i<N;i++) // O(V) time for finding the min height.
    if(A[u][i]>0)
      if(h[i]<h[v])
       v=i;
  int tempu=h[u];
  h[u]=h[v]+1;
  // We already done the relabel, we should now maintain the P[].
  for(int i =0;i<N;i++)
    if(A[u][i]>0)
      if(h[u]==(h[i]+1))
        P[u].push(v);
  for(int i = 0;i<N;i++)
    if(A[i][u]>0&&(h[i]==tempu+1))
      del(i,u); // Here I use a not that good method. I simply did deletion in O(V) time
}

void Output()
{
  for(int i =0;i<N;i++)
  cout << e[i] << ' ';
  cout << endl;
  for(int i =0;i<N;i++)
  cout << h[i] << ' ';
  cout << endl;
}

int main() // There are still some problems such as the flow will go around in the graph again and again and then out.
{
  Read();
  Initial();
  Output();
  while(!E.empty())
  {
    cout << endl;
    int u = E.front();
    if(!Push(u))
      Relabel(u);
    if(e[u]==0)
      E.pop();
    Output();
  }
  cout << e[T] << endl;
}
