/*#include <iostream>
#define INF  10000;

using namespace std;
//pair <int ,int > p[1000];
int N=0,M=0;
int E[100][100];
int d[100];

void output(int * D)
{
  for(int i = 0;i<N;i++)
  cout << d[i] << ' ';
  cout << endl;
}

void Read()
{
  memset(E,-1,sizeof(E));
  cin >> N >> M;
  int v1,v2,e;
  for(int i =0;i<N;i++)
    for(int j = 0 ;j<N;j++)
      E[i][j]=INF;
  for(int i = 0;i<M;i++)
  {
    cin >> v1 >> v2 >> e;
    E[v1][v2]=e;
  }
}

bool BellmanFord(int E[100][100])
{
  d[0]=0;
  for(int i=1;i<N;i++)
  d[i]=INF;
  output(d);
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<N;k++)
        {
          d[k]=(d[k]>d[j]+E[j][k])?d[j]+E[j][k]:d[k];
        }
  for(int j=0;j<N;j++)
    for(int k =0;k<N;k++)
    if(d[k]>d[j]+E[j][k])
      return false;
  return true;
}

int main()
{
  cout << "Start" << endl;
  Read();
  cout << E[0][1] << endl;
  bool b =BellmanFord(E);
  cout << b << endl;
  for(int i =0;i<N;i++)
  {cout << d[i] << endl;cout << "Here";}
  cout << "OK" << endl;
}*/
