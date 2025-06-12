#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void divizori(int n)
{
    cout<<1<<' ';
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)cout<<i<<' '<<n/i<<' ';
    }
    cout<<n<<'\n';
}
int main()
{int n;
    for(int i=1;i<=3;i++)
    {printf("citeste valoarea dorita:");
    cin>>n;
        divizori(n);
    }
}

