/*#include <iostream>
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

void mmultiply(int A[100][100], int B[100][100], int C[100][100]) //A is the Edge Matrix, B is the input Matrix
{
  int TEMP=INF;
  for(int i = 0;i<N;i++)
    for(int j=0;j<N;j++)
    {
      TEMP=INF;
      for(int k=0;k<N;k++)
      {
        if(TEMP>B[i][k]+A[k][j])
          TEMP=B[i][k]+A[k][j];
      }
      C[i][j]=TEMP;
    }
}

void copy(int A[100][100], int B[100][100])
{
  for(int i = 0;i<N;i++)
  for(int j = 0;j<N;j++)
  B[i][j]=A[i][j];
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
  for(int i = 1; 2*i <=2*N;i++)
  {
    mmultiply(E,E,ANS);
    copy(ANS,E);
  }
  output(ANS);
}*/
