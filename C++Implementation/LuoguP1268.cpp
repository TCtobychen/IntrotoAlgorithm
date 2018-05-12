#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M[35][35],index1=0,index2=0,x=0,y=0;

void Find(int n){
  For(1,n+1) for(int j=i+1;j<=n;j++){
    int start=1,ok=1;
    while(start==i || start==j) start++;
    int diff=M[i][start]-M[start][j];
    start++;
    while(start<=n){
      if(start!=i && start!=j){
        int diff2=M[i][start]-M[start][j];
        if(diff!=diff2) {ok=0;break;}
      }
      start++;
    }
    if(ok) {index1=i, index2=j;
      x=(M[i][j]+diff)/2;y=(M[i][j]-diff)/2;
      //cout << "diff is " << diff << endl;
      return;}
  }
}

void Compress(int n){
  //cout << "compress " << index1  << ' ' << index2 << ' ' << y << endl;
  For(index2,n) for(int j=index2;j<n;j++) M[i][j]=M[i+1][j+1];
  For(index2,n) for(int j=1;j<index2;j++) {M[i][j]=M[i+1][j];M[j][i]=M[j][i+1];}
  For(1,n+1) {M[index1][i]+=y;M[i][index1]+=y;}
  For(1,n+1) M[i][i]=0;
}

void output(int k){
  //cout << "OUTPUT" << endl;
  For(1,k+1) {for(int j=1;j<=k;j++) cout << M[i][j] << ' ';cout << endl;}
}

int main(){
  ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N;
  while(N!=0){
  memset(M,0,sizeof(M));
  For(1,N+1) for(int j=i+1;j<=N;j++) {cin >> M[i][j];M[j][i]=M[i][j];}
  //cin.close();
  for(int i=N;i>2;i--){
    //output(i);
    Find(i);
    Compress(i);
  }
  cout << M[1][2] << endl;
  cin >> N;
}
  cin.close();
  return 0;
}
