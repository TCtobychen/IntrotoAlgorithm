#include <iostream>
#include <cstring>
#define For(x,y) for(int i=x;i<y;i++)
using namespace std;

int N;
//int vis[30];
int used[30];
int ans[30],input1[30],input2[30],output[30];

void outputt(int * A)
{
  For(0,N)
  cout << A[i] <<' ';
  cout << endl;
}

void dfs(int n, int add)
{
  //cout << n <<' '<<add << endl;
  //outputt(ans);
  //outputt(used);
  if(n==-1&&add!=1)
  {
    For(0,N)
    cout << ans[i] <<' ';
    cout << endl;
    return ;
  }
  if(ans[input1[n]]>=0)
  {
    if(ans[input2[n]]>=0)
    {
      if(ans[output[n]]>=0)
      {
        int temp=ans[input1[n]]+ans[input2[n]]+add;
        if(temp%N==ans[output[n]])
        {
          if(temp>=N)
            {dfs(n-1,1);return ;}
          else
            {dfs(n-1,0);return ;}
        }
        else
        return ;
      }
      else
      {
        int temp=ans[input1[n]]+ans[input2[n]]+add;
        if(used[temp%N])
          return;
        else
        {
          ans[output[n]]=temp%N;
          used[temp%N]=1;
          if(temp>=N)
            {dfs(n-1,1);used[ans[output[n]]]=0;ans[output[n]]=-1;return ;}
          else
            {dfs(n-1,0);used[ans[output[n]]]=0;ans[output[n]]=-1;return ;}
        }
      }
    }
    else
    {
      if(ans[output[n]]>=0)
      {
        if(!used[(ans[output[n]]-ans[input1[n]]-add+N)%N])
          {
            ans[input2[n]]=(ans[output[n]]-ans[input1[n]]-add+N)%N;
            used[ans[input2[n]]]=1;
            dfs(n-1,(ans[input1[n]]+ans[input2[n]]+add)>N);
            used[ans[input2[n]]]=0;
            ans[input2[n]]=-1;
            return ;
          }
        else
        return ;
      }
      else
      {
        for(int i = N-1;i>=0;i--)
        if(!used[i]&&!used[(i+ans[input1[n]]+add)%N]&&(i!=((i+ans[input1[n]]+add)%N)))
        {
          ans[input2[n]]=i;
          ans[output[n]]=(i+ans[input1[n]]+add)%N;
          used[i]=1;used[ans[output[n]]]=1;
          dfs(n-1,(ans[input1[n]]+ans[input2[n]]+add)>N);
          used[i]=0;used[ans[output[n]]]=0;
          ans[input2[n]]=-1;
          ans[output[n]]=-1;
        }
        return ;
      }
    }
  }
  else
  {
    if(ans[input2[n]]>=0)
    {
      if(ans[output[n]]>=0&&!used[(ans[output[n]]+N-ans[input2[n]]-add)%N])
      {
        ans[input1[n]]=(ans[output[n]]+N-ans[input2[n]]-add)%N;
        used[ans[input1[n]]]=1;
        dfs(n-1,(ans[input1[n]]+ans[input2[n]]+add)>ans[output[n]]);
        used[ans[input1[n]]]=0;
        ans[input1[n]]=-1;
      }
      else
        return ;
    }
    else
    {
      if(ans[output[n]]>=0)
      {
        for(int i = N-1;i>=0;i--)
        if(!used[i]&&!used[(ans[output[n]]+N-i-add)%N]&&(i!=((ans[output[n]]+N-i-add)%N)))
        {
          ans[input1[n]]=i;ans[input2[n]]=(ans[output[n]]+N-i-add)%N;
          used[i]=1;used[ans[input2[n]]]=1;
          dfs(n-1,(ans[input1[n]]+ans[input2[n]]+add)>ans[output[n]]);
          used[i]=0;used[ans[input2[n]]]=0;
          ans[input1[n]]=-1;ans[input2[n]]=-1;
        }
        return ;
      }
      else
      {
        for(int i = N-1;i>=0;i--)
          for(int j = 1;j<N;j++)
          {
            if(!used[(2*i+j+add)%N]&&((2*i+j+add)%N)!=i&&((2*i+j+add)%N)!=((i+j)%N))
            {
              ans[input1[n]]=i;
              ans[input2[n]]=(i+j)%N;
              ans[output[n]]=(2*i+j+add)%N;
              used[i]=1;used[ans[input2[n]]]=1;used[ans[output[n]]]=1;
              //outputt(ans);
              //outputt(used);cout <<"ROUND" << endl;
              dfs(n-1,(ans[input1[n]]+ans[input2[n]]+add)>ans[output[n]]);
              used[i]=0;used[ans[input2[n]]]=0;used[ans[output[n]]]=0;
              ans[input1[n]]=-1;
              ans[input2[n]]=-1;
              ans[output[n]]=-1;
            }
          }
        return ;
      }
    }
  }
}

int main()
{
  cin >> N;
  char c;
  memset(ans,-1,sizeof(ans));
  memset(used,0,sizeof(used));
  For(0,N)
  {
    cin >> c;
    input1[i]=(int)(c-'A');
  }
  For(0,N)
  {
    cin >> c;
    input2[i]=(int)(c-'A');
  }
  For(0,N)
  {
    cin >> c;
    output[i]=(int)(c-'A');
  }
  dfs(N-1,0);
  For(0,N)
  //cout << ans[i] << ' ';
  //cout << endl;
  return 0;
}
