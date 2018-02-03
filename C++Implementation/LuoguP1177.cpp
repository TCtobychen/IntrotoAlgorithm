#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x ;i<y;i++)
using namespace std;
int n;

long long int mid(long long int i, long long int j, long long int k)
{
  if(i<j)
    return mid(j,i,k);
  if(j>=k)
    return j;
  return min(i,k);
}

void output(long long int *a,int n)
{
  For(0,n)
  cout << a[i] <<' ';
  cout << endl;
  return ;
}

void quicksort(long long int * a, int start, int end)
{
  if(start>=end-1)
    return;
  int key;
  long long int v=mid(a[start],a[end-1],a[(start+end)/2]);
  if(v==a[start])
    key=start;
  if(v==a[end-1])
    key=end-1;
  if(v==a[(start+end)/2])
    key=(start+end)/2;
  int i =start, j=end-1;
  //cout << a[key] << a[start] << endl;
  a[key]=a[start];
  a[start]=v;
  key=start;
  while(i!=j)
  {
    //output(a,n);
    while(a[j]>=v&&j!=i)
    j--;
    //cout << key <<' '<<j << endl;
    a[key]=a[j];
    a[j]=v;
    key=j;
    //output(a,n);
    while(a[i]<=v&&i!=j)
    i++;
    //cout << key <<' '<<i << endl;
    a[key]=a[i];
    a[i]=v;
    key=i;
    //output(a,n);
  }
  int newkey=key;
  if(key>(start+end)/2)
    {while(a[newkey]==a[key]&&newkey!=(start+end)/2)
    newkey--;newkey++;}
  if(key<(start+end)/2)
    {while(a[newkey]==a[key]&&newkey!=(start+end)/2)
    newkey++;newkey--;}
  key=newkey;
  quicksort(a,start,key);
  quicksort(a,key+1,end);
}


int main()
{
  long long int a[100000];
  cin >> n;
  For(0,n)
  cin >> a[i];
  quicksort(a,0,n);
  For(0,n)
  cout << a[i] << ' ';
  cout << endl;
  return 0;
}
