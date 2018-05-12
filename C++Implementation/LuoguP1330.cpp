#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,M,cnt=0;
int sum[2]={0},temp[2]={0};
int head[10010],c[10010];
struct Edge {
  int u,v,next;
  Edge(){}
  Edge(int _u, int _v, int _next){
    u=_u,v=_v,next=_next;
  }
};
Edge edge[100010];

void add(int u, int v){
  edge[cnt]=Edge(u,v,head[u]);
  head[u]=cnt++;
  edge[cnt]=Edge(v,u,head[v]);
  head[v]=cnt++;
}

bool dfs(int n, int color){
  //cout << n <<' ' << color << endl;
  if(c[n]!=-1){
    if(c[n]==color) return true;
    return false;
  }
  else{
    c[n]=color,sum[color]++;
    int now=head[n];bool ans=true;
    while(now!=-1&&ans){
      ans=dfs(edge[now].v,1-color);
      now=edge[now].next;
    }
    return ans;
  }
}

void getleast(){  // Everytime put the smaller one into sum[0]
  int a=sum[0]-temp[0],b=sum[1]-temp[1];
  int minn,maxx;
  minn=(a>b)?b:a;
  maxx=a+b-minn;
  sum[0]=temp[0]+minn,sum[1]=temp[1]+maxx;
  temp[0]=sum[0],temp[1]=sum[1];
}

void output(){
  For(1,N+1) cout << c[i] << ' ';
  cout << endl;
}

void read(int &t){
  int x=0;char c;
  c=getchar();
  while(c<'0'||c>'9') c=getchar();
  while(c>='0'&& c<='9') {x=x*10+c-'0';c=getchar();}
  t=x;
}

int main()
{
   int t1,t2;
   memset(c,-1,sizeof(c));
   memset(head,-1,sizeof(head));
   bool bans=true;
   //ifstream cin;cin.open("/Users/yang/Desktop/Learning C++/Learning C++/test.in");
   cin >> N >> M;
   For(0,M) {read(t1);read(t2);add(t1,t2);}
   //cin.close();
   For(1,N+1) if(c[i]==-1&&bans) {bans=dfs(i,1);getleast();
     //output();
   }
   if(bans) cout << sum[0] << endl;
   else cout << "Impossible" << endl;
   return 0;
}
