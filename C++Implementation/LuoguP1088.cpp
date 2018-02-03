#include <iostream>
#include <cstring>
#include <algorithm>
#define For(x,y) for(int i =x;i<y;i++)
using namespace std;

int a[10010];
int N,M;

void output()
{
    For(0,N)
    cout << a[i] <<' ';
    cout << endl;
}

void increm()
{
  //output();
    int tpm=0,index,tpn=10050;
    for(int i = N-1;i>=0;i--)
    {
        tpm=max(tpm,a[i]);
        if(a[i]!=tpm)
        {
            int j;
            for(j =i+1;j<N;j++)
            if(a[j]>a[i])
                {tpn=min(tpn,a[j]);
                if(a[j]==tpn) index=j;}
            int t=a[i];a[i]=a[index];a[index]=t;
            sort(a+i+1,a+N);
            break;
        }
    }
}

int main()
{
    int sum=0;
    cin >> N >> M;
    For(0,N)
    cin >> a[i];
    For(0,M)
    increm();
    output();
    return 0;
}
