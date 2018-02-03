#include <iostream>
using namespace std;

int main()
{
  double s[4]={3.0,3.3,3.7,4.0};
  for(int i = 0;i<3;i++)
    for(int j=1;j<4;j++)
      for(int k = 0;k<4;k++)
        for(int l=1;l<4;l++)
          for(int m=0;m<4;m++)
            for(int n=1;n<2;n++)
            {
              double score1=(s[i]*5+s[j]*4+s[k]*3+s[l]*2+s[m]*2+s[n]+9.9)/20;
              double score2=(s[i]*5+s[j]*4+s[k]*3+s[l]*2+s[m]*2+s[n]+9.9*2)/23;
              double score3=(s[i]*5+s[j]*4+s[k]*3+s[l]*2+s[m]*2+s[n]+9.9*2+3*3.7)/26;
              if(score1>=3.345 && score1 < 3.355 && score2>=3.335 && score2 <3.345 && score3 >=3.375 && score3 < 3.385 )
              {cout << s[i] <<' '<<s[j] << ' ' << s[k] <<' ' << s[l] << ' '<<s[m] <<' ' <<s[n]<< endl;}
            }
}
