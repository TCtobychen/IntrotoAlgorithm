#include <iostream>
using namespace std;
int n,p;
int C[300]={0},U[300]={0},L[300]={0};
int W[210][210]={0};

void Read()
{
  /*memset(C,0,sizeof(C));
  memset(L,0,sizeof(L));
  memset(U,0,sizeof(U));
  memset(W,-1,sizeof(W));*/
  cin >> n >> p;
  for(int i=1;i<=n;i++)
  {
    cin >> C[i] >> U[i];
  }
  int v1,v2,w;
  for(int i =0;i<p;i++)
  {
    cin >> v1 >> v2 >> w;
    W[v1][v2]=w;
    L[v2]=L[v1]+1;
  }
}

int Pass(int l, int start)
{
  int nex=0,end=0;
  for(int j = start;L[j]==l;j++)
   nex=j;
  nex++;
  for(int j = nex;L[j]==l+1;j++)
   end=j;
  end++;
  for(int i = start;i<nex;i++)
    if(C[i]>0)
      for(int j = nex;j<end;j++)
      {
        C[j]+=W[i][j]*C[i];
      }
  for(int j = nex;j<end;j++)
    C[j]-=U[j];
  return nex;
}

int main()
{
  Read();
  // L is well constructed.
  //cout << L[2] << "????";
  int s=1;
  for(int i = 0;i<L[n];i++)
   s=Pass(i,s);
  //cout << "!!!!" << s << endl;
  int ok = 0;
  //cout << C[5] << "C5" ;
  for(int i = s;i<=n;i++)
    if(C[i]>0)
    {
      cout << i << ' ' <<C[i] << endl;
      ok=1;
    }
  if(!ok)
    cout << "NULL" << endl;
}
