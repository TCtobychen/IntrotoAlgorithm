#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,vis[100010];
queue<int> p[100010];
queue<int> pq;

void find(int n){
  vis[n]=1;
  while(!p[n].empty()){

  }
}

int main()
{
  cin >> N;int t;
  For(0,N) {cin >> t;p[t].push(i+1);if(t==(i+1)) pq.push(t);}
  while(!pq.empty()){
    t=pq.front();
    dojob(t);
    pq.pop();
  }
  For(1,N+1) cout << vis[i]<<' ';cout <<endl;
  return 0;
}
