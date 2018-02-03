#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N,R,Q;
struct candidate{
  int number;
  long long int s,w;
};
candidate c[200000];
candidate d[200000];
int win[200000];

void output()
{
  For(0,2*N)
  cout << c[i].s << ' ';
  cout << endl;
}

bool comparison(candidate c1, candidate c2)
{
  if(c1.s!=c2.s)
    return c1.s > c2.s;
  return c1.number < c2.number;
}

int match(int n)
{
  if(c[2*n].w>c[2*n+1].w)
    {c[2*n].s++;return 2*n;}
  c[2*n+1].s++;
  return (2*n+1);
}

void copy(candidate *c1, candidate *c2)
{
  c1->number=c2->number;
  c1->s=c2->s;
  c1->w=c2->w;
}

int getnextwin(int j)
{
  if(j==2*N)
    return j;
  do{j++;}while(win[j]==0&&j<2*N);
  return j;
}
int getnextlose(int k)
{
  if(k==2*N)
    return k;
  do{k++;}while(win[k]==1&&k<2*N);
  return k;
}

void run()
{
  memset(win,0,sizeof(win));
  memset(d,0,sizeof(d));
  For(0,N)
  win[match(i)]=1;
  //output();
  //cout << "Before" << endl;
  int j=-1,k=-1;
  j=getnextwin(j);
  k=getnextlose(k);
  //cout << j <<' ' << k << "!!!!!";
  For(0,2*N)
  {
    if(comparison(c[j],c[k]))
      {copy(&d[i],&c[j]);j=getnextwin(j);}
    else
    {
      copy(&d[i],&c[k]);k=getnextlose(k);
    }
  }
  For(0,2*N)
  copy(&c[i],&d[i]);
  //output();
}

int main()
{
  cin >> N >>R >>Q;
  For(0,2*N)
  {cin >> c[i].s;c[i].number=i+1;}
  For(0,2*N)
  cin >> c[i].w;
  c[2*N].number=100000;
  c[2*N].s=0;
  c[2*N].w=0;
  sort(c,c+2*N,comparison);
  For(0,R)
  run();
  cout << c[Q-1].number << endl;
  return 0;
}
