#include <iostream>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

struct cloud1{int x,y,w,h;}c1[100010];
struct cloud2{int x,y,w,h;}c2[100010];
int T,N,ok=0;

bool comparison(cloud2 cc1, cloud2 cc2){
    return (cc1.y+cc1.h-cc2.y-cc2.h)>(cc2.x+cc2.w-cc1.x-cc1.w);
}

int col(int m, int n){
    int t1=c2[n].x-c1[m].x-c1[m].w+1;
    int t2=c2[n].x+c2[n].w-c1[m].x-1;
    int t3=c1[m].y-c2[n].y-c2[n].h+1;
    int t4=c1[m].y+c1[m].h-c2[n].y-1;
    if(t2>=t3 && t4>=t1) return 1;
    if(t2<t3) return -1;
    return 0;
}

void findcol(int x1,int start, int end){
    if(start>=end) return ;
    int mid=(start+end)/2,s=col(x1,mid);
    if(s==1) {ok=1;return;}
    if(s==-1) {findcol(x1,mid+1,end);}
    if(s==0) {findcol(x1,start,mid-1);}
}

void dojob(){
    cin >> N;
    int x,y,w,h,d,n1=0,n2=0;ok=0;
    For(0,N) {cin >> x >>y >> w>>h>>d;
        if(d==0) {c1[n1].x=x;c1[n1].y=y;c1[n1].w=w;c1[n1].h=h;n1++;}
        if(d==1) {c2[n2].x=x;c2[n2].y=y;c2[n2].w=w;c2[n2].h=h;n2++;}
    }
    sort(c2,c2+n2,comparison);
    For(0,n1) if(!ok) findcol(i,0,n2);
    if(ok) cout << 2 << endl;
    else cout <<1 << endl;
}

int main()
{
    cin >> T;
    for(int k=0;k<T;k++) dojob();
    return 0;
}
