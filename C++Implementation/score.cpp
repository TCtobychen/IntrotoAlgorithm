#include <iostream>
using namespace std;

int main()
{
  double s[4]={3.0,3.3,3.7,4.0};
  for(int i = 0;i<3;i++)
    for(int j=0;j<4;j++)
      for(int k = 0;k<3;k++)
        for(int l=1;l<3;l++)
          for(int m=1;m<4;m++)
            for(int n=1;n<2;n++)
            {
              double score=(s[i]*5+s[j]*4+s[k]*3+s[l]*2+s[m]*2+s[n]+9.9)/20;
              if(score>3.344 && score < 3.354)
              {cout << s[i] <<' '<<s[j] << ' ' << s[k] <<' ' << s[l] << ' '<<s[m] <<' ' <<s[n]<< endl;}
            }
}
