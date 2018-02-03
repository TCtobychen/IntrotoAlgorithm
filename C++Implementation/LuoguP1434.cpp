#include <iostream>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int r,c;
int ans[110][110];
int H[110][110];
int ANS=0;
pair<pair<int, int>, int> node[10010];

bool comparison(pair<pair<int, int>, int> node1, pair<pair<int, int>, int> node2)
{
  return node1.second > node2.second;
}

void dfs(int x, int y, int depth)
{
  //cout << x << ' ' << y <<' '<<depth <<endl;
  if(ans[x][y]>=depth)
    return ;
  ans[x][y]=depth;
  ANS=max(ANS,depth);
  if(x>0&&H[x-1][y]<H[x][y])
    dfs(x-1,y,depth+1);
  if(x<r-1&&H[x+1][y]<H[x][y])
    dfs(x+1,y,depth+1);
  if(y>0&&H[x][y-1]<H[x][y])
    dfs(x,y-1,depth+1);
  if(y<c-1&&H[x][y+1]<H[x][y])
    dfs(x,y+1,depth+1);
  return ;
}

void output()
{
  For(0,r)
  {
    for(int j =0;j<c;j++)
    cout << ans[i][j] <<' ';
    cout << endl;
  }
}

int main()
{
  cin >> r >> c;
  memset(ans,0,sizeof(ans));
  int number=0;
  int h;
  For(0,r)
    for(int j = 0;j<c;j++)
    {
      cin >> h;
      H[i][j]=h;
      node[number].first.first=i;
      node[number].first.second=j;
      node[number].second=h;
      number++;
    }
  sort(node,node+number,comparison);
  //cout << number<< endl;
  For(0,number)
  {
    int x=node[i].first.first, y=node[i].first.second;
    if(ans[x][y]==0)
    dfs(x,y,1);
  }
  //output();
  cout << ANS <<endl;
  return 0;
}
