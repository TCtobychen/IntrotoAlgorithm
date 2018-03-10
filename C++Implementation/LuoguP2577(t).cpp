#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[201],b[201],sum[201],f[201][40001],g[201][40001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if((b[i]<b[j])||(b[i]==b[j])&&(a[i]<a[j]))
            {
                int t;
                t=a[i];a[i]=a[j];a[j]=t;
                t=b[i];b[i]=b[j];b[j]=t;
            }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    memset(f,27,sizeof(f));
    memset(g,27,sizeof(g));
    f[0][0]=0;g[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=sum[i];j++)
        {
            if(j>=a[i])
                f[i][j]=min(max(f[i-1][j-a[i]],j+b[i]),max(g[i-1][j-a[i]],j+b[i]));
            g[i][j]=min(max(f[i-1][j],sum[i]-j+b[i]),max(g[i-1][j],sum[i]-j+b[i]));
        }
    int ans=1000000000;
    for(int i=0;i<=sum[n];i++)
        ans=min(min(ans,f[n][i]),g[n][i]);
    cout<<ans<<endl;
}
