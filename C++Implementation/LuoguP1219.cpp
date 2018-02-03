#include <iostream>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int A[100000][14];
int a[14];
bool col[14],check1[30],check2[30];
int N;
long long int num=0;

void output()
{
  For(0,N)
  cout << a[i]+1 <<' ';
  cout << num ;
  cout << endl;
}

void dfs(int n)
{
  //output();
  if(n==N-1)
  For(0,N)
  if(!col[i]&&!check1[13+n-i]&&!check2[n+i])
  {
    a[n]=i;
    //output();
    for(int j=0;j<N;j++)
    A[num][j]=a[j];
    num++;
    a[n]=-1;
    return ;
  }
  For(0,N)
  if(!col[i]&&!check1[13+n-i]&&!check2[n+i])
  {
    col[i]=1;
    check1[13+n-i]=1;
    check2[n+i]=1;
    a[n]=i;
    dfs(n+1);
    col[i]=0;
    check1[13+n-i]=0;
    check2[n+i]=0;
    a[n]=-1;
  }
}

int main()
{
  cin >> N;
  memset(col,0,sizeof(col));
  memset(check1,0,sizeof(check1));
  memset(check2,0,sizeof(check2));
  memset(a,-1,sizeof(a));
  memset(A,0,sizeof(A));
  /*a[0]=3;col[3]=check1[10]=check2[3]=1;
  a[1]=6;col[6]=check1[8]=check2[7]=1;
  a[2]=4;col[4]=check1[11]=check2[6]=1;
  dfs(3);*/

  dfs(0);
  For(0,3)
    {for(int j  =0;j<N;j++)
      cout << A[i][j]+1 << ' ';
    cout << endl;}
  cout << num << endl;
  return 0;
}

//missing 64713528 63571428 57263148 47526138
