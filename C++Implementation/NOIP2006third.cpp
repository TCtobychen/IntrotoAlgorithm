#include <iostream>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int M,N;
int t=0;
int machine[20];
int read[20];
struct Order{
  int number;
  int th;
  int mac;
  int time;
};
Order o[400];

void Read()
{
  cin >> M >> N;
  For(0,M*N)
    cin >> o[i];
}

int checknext(int now)
{
  For(0,M)
  {
    for(int i=now;i<N;i++)
      if()
  }
}

int main()
{
  Read();
  int done = 0;
  int now=0;
  while(!done)
  {
    done=checknext(now);
  }
}
