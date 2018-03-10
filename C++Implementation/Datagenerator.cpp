#include <iostream>
#include <ctime>
#define For(x,y) for(int i=x;i<y;i++)
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;

int main()
{
  srand((unsigned)time(NULL));
  cout << 5 << endl;
  For(0,5) cout << random(1,20) <<' '<<random(1,20) << endl;
  return 0;
}
