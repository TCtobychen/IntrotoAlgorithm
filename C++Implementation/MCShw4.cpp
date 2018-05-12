#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

bool isprime(int n){
  if(n==1) return false;
  if(n==2) return true;
  For(2,sqrt(n)+1) if(n%i==0) return false;
  return true;
}

bool dojob1(int n){
  // This is the function for judging if there are two different primes whose sum is n
  // returns true if Mr.S knew Mr.P did not know.
  int a=2, b=n/2+1;
  if(n>101) a=n-99,b=n-2;
  For(a,b) if(isprime(i)&&isprime(n-i)) return false;
  return true;
}

bool dojob3(int pr){
  // This function enumerates all the possible products, and check if their sum satisfies
  // the property of "knew not know"
  // return true if exactly one sum satisfies this property, which makes pr a feasible solution.
  int count=0;
  For(2,sqrt(pr)+1) if(pr%i==0&&i<pr/i&&i<100&&pr/i<100) if(dojob1(i+pr/i)) count++;
  if(count==1) return true;
  return false;
}

bool dojob2(int n){
  // This is the function that examines every product of its composite numbers
  // If there is exactly one product whose dojob1(composite's sum)==true
  // then this function returns true, which means Mr.S can conclude by Mr.P's knowing.
  int num=0;
  For(2,n/2+1){
    int pr=i*(n-i);
    if(dojob3(pr)) num++;
  }
  if(num==1) return true;
  return false;
}

bool test(int a, int b){
  // This is the main testing function
  int cnt=0;
  queue<int> sum;
  int p=a*b, s=a+b;
  For(2,sqrt(p)+1) if(p%i==0&&i<p/i) {cnt++;sum.push(i+p/i);}
  // First we check whether a*b has unique expression
  if(cnt<=1) return false;
  // Then we check if Mr.S can "knew not know"
  if(!dojob1(s)) return false;
  cnt=0;
  // Now we check if Mr.P can conclude by enumerating all possible sums
  while(!sum.empty()){
    int temp=sum.front();
    if(dojob1(temp)) cnt++;
    sum.pop();
  }
  if(cnt!=1) return false;
  // At the end we enumerate the cases of Mr.S
  return dojob2(s);
}

int main()
{
  // Here we check all the cases where 2<=m<n<=100
  For(2,100) for(int j=i+1;j<=100;j++) if(test(i,j)) cout << i << ' ' << j << endl;
  return 0;
}
