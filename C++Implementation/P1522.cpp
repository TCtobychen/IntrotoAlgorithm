#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,vis[160];
vector<int> v1,v2;
int e[160][160];
double x[160],y[160],MAX[160],maxxx=0;
double W[160][160],A[160][160],B[160][160];
double ans=1e9;

void output(double T[160][160]){
  For(1,N+1) {for(int j=1;j<N+1;j++) cout << T[i][j] << ' ';cout << endl;}
}

void output(int T[160][160]){
  For(1,N+1) {for(int j=1;j<N+1;j++) cout << T[i][j] << ' ';cout << endl;}
}

double dis(int m, int n){
  double dist=(x[m]-x[n])*(x[m]-x[n])+(y[m]-y[n])*(y[m]-y[n]);
  double ANS=sqrt(dist);
  //cout << "DIS" << ANS << endl;
  return ANS;
}

void calW(){
  For(1,N+1) for(int j=1;j<N+1;j++) if(e[i][j]) W[i][j]=W[j][i]=dis(i,j);
  //cout << "W!!!!" << endl;
  //output(W);
}

void bfs(){
  memset(vis,0,sizeof(vis));
  queue<int> q;
  q.push(1);vis[1]=1;v1.push_back(1);
  while(!q.empty()){
    int t=q.front();q.pop();
    For(1,N+1) if(e[t][i]&&!vis[i]) {q.push(i);v1.push_back(i);vis[i]=1;}
  }
  //For(0,v1.size()) cout << v1[i] << ' '; cout << endl;
  For(1,N+1) if(!vis[i]) v2.push_back(i);
}

void copy(double C[160][160], double D[160][160]){
  For(1,N+1) for(int j=1;j<=N;j++) D[i][j]=C[i][j];
}

void multiply(double C[160][160], double D[160][160], double E[160][160]){
  For(1,N+1) for(int j=1;j<=N;j++){
    double temp=1e9;
    for(int k=1;k<N+1;k++) temp=min(temp,C[i][k]+D[k][j]);
    E[i][j]=temp;
  }
}

int find(int P){
  int cnt=1,a=2;
  while(a<P) {a*=a;cnt++;}
  return cnt;
}

void dojob(){
  //cout << "Connecting " << m << ' ' << n << endl;
  //W[m][n]=W[n][m]=dis(m,n);
  copy(W,A);
  int t=find(N);
  For(0,t+2){
    multiply(A,A,B);
    copy(B,A);
  }
  //output(A);
  //double temp=0;
  //For(1,N+1) for(int j=1;j<N+1;j++) temp=max(temp,A[i][j]);
  //cout << temp << endl;
  //W[n][m]=W[m][n]=1e9;
  //return temp;
}

void read(int &t){
  char ch=getchar();
  while(ch<'0' || ch > '9') ch=getchar();
  t=ch-'0';
  return ;
}

double maxx(int m){
  double s=0;
  For(1,N+1) if(A[m][i]<1e9) s=max(s,A[m][i]);
  return s;
}

int main()
{
  memset(e,0,sizeof(e));
  //ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N;
  double x1,y1;
  For(1,N+1) {cin >> x1 >> y1;x[i]=x1;y[i]=y1;}
  For(1,N+1) for(int j=1;j<N+1;j++) read(e[i][j]);
  //output(e);
  //cin.close();
  For(1,N+1) for(int j=1;j<=N;j++) W[i][j]=1e9;
  For(1,N+1) W[i][i]=0;
  calW();
  bfs();
  dojob();
  For(1,N+1) {MAX[i]=maxx(i);maxxx=max(maxxx,MAX[i]);}
  For(0,v1.size()) for(int j=0;j<v2.size();j++) ans=min(ans,dis(v1[i],v2[j])+MAX[v1[i]]+MAX[v2[j]]);
  //cout << maxxx << endl;
  printf("%6f",max(ans,maxxx));
  return 0;
}
