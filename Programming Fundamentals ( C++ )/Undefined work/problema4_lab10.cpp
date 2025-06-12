#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void rasturnat(int n)
{
  int inv=0;
  while(n!=0)
  {
      inv=inv*10+n%10;
      n/=10;
  }
  cout<<inv<<'\n';
}
int main()
{int n;
    for(int i=1;i<=3;i++)
    {printf("citeste valoarea dorita:");
    cin>>n;
        rasturnat(n);
    }
}


