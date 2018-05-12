#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

/*
This program calculates the number of IIA functions and output all the possible functions that
does not violate IIA and Unanimity.
So the output is two dictator functions and the number of IIA functions, which is 94.
*/

int v[2][6][3]; // All the 36 possible inputs are stored here.
int w[36][3]; // This is the possible output.
int vi[36][3],b[3]={1,2,3},vis[3],num=0,temp[36][3],temp1[3],k,cnt=0,cnt1=0;
int p[3][4][4]; // This is for judging IIA. We just enumerate all possible preferences over
                // any two candidate and record the result. So any conflict with pre-exist result
                // means IIA is not satisfied. p[] is initialized to -1 so that the first result can be recorded.

void dfs(int t){ // Using dfs to fill all possible 36 inputs.
  if(t==3){
    For(0,3) v[k][num][i]=temp1[i]; num++;return;
  }
  For(0,3) if(vis[i]==0) {
    vis[i]=1;temp1[t]=b[i];dfs(t+1);vis[i]=0;temp1[t]=0;
  }
  return ;
}

void input(int a[6][3]){ // The function for filling inputs.
  num=0;
  memset(vis,0,sizeof(vis));
  memset(temp,0,sizeof(temp));
  For(0,3) {temp1[0]=b[i];vis[i]=1;dfs(1);vis[i]=0;temp1[0]=0;}
}

int bf(int c[3]){  // This is for judging IIA considering candidates 1 and 2.
  int i;
  for(i=0;i<3;i++) if(c[i]==1||c[i]==2) break;
  if(c[i]==1) return 1;
  else return 0;
}

int bs(int c[3]){  // This is for judging IIA considering candidates 1 and 3.
  int i;
  for(i=0;i<3;i++) if(c[i]==1||c[i]==3) break;
  if(c[i]==1) return 1;
  else return 0;
}

int bt(int c[3]){  // This is for judging IIA considering candidates 2 and 3.
  int i;
  for(i=0;i<3;i++) if(c[i]==2||c[i]==3) break;
  if(c[i]==2) return 1;
  else return 0;
}

bool check(int m){ // return false if IIA is not satisfied.
  int a=m/6,b=m%6,a1,b1,a2,b2,a3,b3,t1,t2,t3;
  a1=bf(v[0][a]),b1=bf(v[1][b]),t1=bf(temp[m]);
  if(p[1][2][2*a1+b1]!=-1&&p[1][2][2*a1+b1]!=t1) return false;
  a2=bs(v[0][a]),b2=bs(v[1][b]),t2=bs(temp[m]);
  if(p[1][3][2*a2+b2]!=-1&&p[1][3][2*a2+b2]!=t2) return false;
  a3=bt(v[0][a]),b3=bt(v[1][b]),t3=bt(temp[m]);
  if(p[2][3][2*a3+b3]!=-1&&p[2][3][2*a3+b3]!=t3) return false;
  return true;
}

void copy(int ttt[3],int m){ // We have a temp space storing the DFS results for output.
  For(0,3) w[m][i]=ttt[i];    // This functions copies the temp result into the actual result so that
}                              // the actual result can be output.

void output1(int m){      // Output result function.
  For(0,m+1) {for(int j=0;j<3;j++) cout << w[i][j]<<' ';cout << endl;}
  cout << "END of this case. " << endl << endl;
}

bool check1(){       // This checks unanimity, which kind of uses the data of IIA.
  if(p[1][2][0]==1||p[1][2][3]==0) return false;
  if(p[1][3][0]==1||p[1][3][3]==0) return false;
  if(p[2][3][0]==1||p[2][3][3]==0) return false;
  return true;
}

void Dfs(int t, int m){   // The main DFS function that searching for feasible results for 36 outputs.
  if(t==3){
    if(check(m)) {        // t==3 means one output is generated, then we check if IIA is satisfied.
      int a=m/6,b=m%6,a1,b1,a2,b2,a3,b3,t1,t2,t3,tt1,tt2,tt3;
      a1=bf(v[0][a]),b1=bf(v[1][b]),a2=bs(v[0][a]),b2=bs(v[1][b]),a3=bt(v[0][a]),b3=bt(v[1][b]);
      tt1=bf(temp[m]),tt2=bs(temp[m]),tt3=bt(temp[m]);
      t1=p[1][2][2*a1+b1],t2=p[1][3][2*a2+b2],t3=p[2][3][2*a3+b3];
      p[1][2][2*a1+b1]=tt1;
      p[1][3][2*a2+b2]=tt2;
      p[2][3][2*a3+b3]=tt3;
      copy(temp[m],m);if(m==35) {cnt++;if(check1()) {cnt1++;output1(m);}} else Dfs(0,m+1); // If IIA, we either output or dfs for the next output.
    p[1][2][2*a1+b1]=t1;
    p[1][3][2*a2+b2]=t2;
    p[2][3][2*a3+b3]=t3;
  }
    return ;
  }
  For(0,3) if(vi[m][i]==0){      // Using dfs to search for all possible cases for one output.
    vi[m][i]=1,temp[m][t]=b[i];
    Dfs(t+1,m);
    vi[m][i]=0,temp[m][t]=0;
  }
  return;
}

int main()
{
  memset(w,0,sizeof(w));
  memset(temp1,0,sizeof(temp1));
  for(k=0;k<2;k++) input(v[k]);
  memset(vi,0,sizeof(vi));
  memset(temp,0,sizeof(temp));
  memset(p,-1,sizeof(p));
  Dfs(0,0);
  cout <<"There are " <<cnt <<" IIA functions. "<< endl;
  cout << cnt1 << " of them are dictators. "<<  endl;
  cout << cnt-cnt1 << " of them violate unanimity. " << endl;
  return 0;
}
