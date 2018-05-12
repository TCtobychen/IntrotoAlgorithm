#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <stack>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,temp=0;
int nex[1000010];
int vis[1000010];
int num[1000010];
int *p=&temp;

void output(){
  For(1,N+1) cout << num[i] <<' ';
  cout << endl;
}

void dojob(int k){
  //output();
  stack<int> s;
  s.push(k);
  vis[k]=1;
  while(!vis[nex[k]]){
    k=nex[k];
    s.push(k);
    vis[k]=1;
  }
  if(num[nex[k]]==0){  // It forms a totally new circle.
    stack<int> w;int cnt=0;
    while(s.top()!=nex[k]){
      w.push(s.top());
      s.pop();
      cnt++;
    }
    w.push(s.top());
    s.pop();
    cnt++;
    while(!w.empty()){
      int t=w.top();num[t]=cnt;
      w.pop();
    }
    while(!s.empty()){
      int t=s.top();
      cnt++;num[t]=cnt;
      s.pop();
    }
    return ;
  }
  else{
    int cnt=num[nex[k]];
    while(!s.empty()){
      int t=s.top();
      cnt++;num[t]=cnt;
      s.pop();
    }
    return ;
  }
}

int main()
{
  //ifstream cin; cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
  cin >> N;
  For(0,N) cin >> nex[i+1];
  //cin.close();
  memset(num,0,sizeof(num));
  memset(vis,0,sizeof(vis));
  For(1,N+1) {if(num[i]==0) dojob(i); cout << num[i] << endl;}
  return 0;
}
