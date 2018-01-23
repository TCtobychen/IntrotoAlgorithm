#include <iostream>
#define INF  10000;
using namespace std;
int E[100][100];
int L1[100][100],ANS[100][100];
int N=0,M=0;

void Read()
{
  cin >> N >> M;
  int v1,v2,e;
  for(int i =0;i<N;i++)
    for(int j = 0 ;j<N;j++)
      {if(i==j) {E[i][j]=0;L1[i][j]=0;} else {E[i][j]=INF;L1[i][j]=INF;}}
  for(int i = 0;i<M;i++)
  {
    cin >> v1 >> v2 >> e;
    E[v1][v2]=e;
    L1[v1][v2]=e;
  }
}

void copy(int A[100][100], int B[100][100])
{
  for(int i = 0;i<N;i++)
  for(int j = 0;j<N;j++)
  B[i][j]=A[i][j];
}

void mmultiply(int A[100][100], int B[100][100])
{
  for(int i =0;i<N;i++)
  {
    for(int j =0;j<N;j++)
      for(int k =0;k<N;k++)
      {
        B[j][k]=((A[j][i]+A[i][k])>A[j][k])?A[j][k]:(A[j][i]+A[i][k]);
      }
    copy(B,A);
  }
}

void output(int A[100][100])
{
  for(int i =0;i<N;i++)
    {for(int j=0;j<N;j++)
    cout << A[i][j] << ' ';
    cout << endl;}
}

int main()
{
  Read();
  mmultiply(E,ANS);
  output(ANS);
}
