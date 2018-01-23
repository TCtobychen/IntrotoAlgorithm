#include <iostream>
#include <queue>
#include <set>
using namespace std;
int E[100][100];
int p[100];
int cst=0;
int A[100][100];
int N,M,S,T;

void Read()
{
  int v1,v2,e;
  cin >> N >> M >> S >> T;
  memset(A,-1,sizeof(A));
  memset(E,-1,sizeof(E));
  for(int i =0;i<M;i++)
  {
    cin >> v1 >> v2 >> e;
    E[v1][v2]=e;
    A[v1][v2]=e;
    A[v2][v1]=0;
  }
}

int bfs(int B[100][100])
{
  cst=100000;
  memset(p,-1,sizeof(p));
  queue<int> q;
  set<int> s;
  q.push(S);
  p[S]=S;
  s.insert(S);
  int ok=1;
  while(ok && !q.empty())
  {
    //cout << "HERE" << endl;
    int t=q.front();
    for(int i =0;i<N;i++)
      if(B[t][i]>0)
      {
        cout << t << ' ' << i << endl;
        if(i==T)
        {
          if(cst>B[t][i])
            cst=B[t][i];
          cout << "???" << endl;
          p[T]=t;ok=0;break;
        }
        else
        {
          if(!s.count(i))
            {s.insert(i);q.push(i);p[i]=t;if(cst>B[t][i]) cst=B[t][i];}
        }
      }
    q.pop();
  }
  cout << ok << "!!!" << endl;
  //ok=1-ok;
  return 1-ok;
}

void augment(int B[100][100])
{
  int t = T;
  while(t!=p[t])
  {
    B[p[t]][t]-=cst;
    B[t][p[t]]+=cst;
    t=p[t];
  }
}

int main ()
{
  Read();
  while(bfs(A))
   {augment(A);}
  int sum=0;
  for(int i = 0;i<N;i++)
    if(A[i][S]>0)
      sum+=A[i][S];
  cout << sum << endl;
}
