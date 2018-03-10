#include <iostream>
#include <algorithm>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

long long int N;

long long int cnt(int n)
{
  int ans=0;
  while(n%5==0) n/=5,ans++;
  return ans;
}

int main()
{
  cin >> N;
  long long int num=0;
  For(5,N+1) {if(i%5)}
  cout << num << endl;
  return 0;
}
