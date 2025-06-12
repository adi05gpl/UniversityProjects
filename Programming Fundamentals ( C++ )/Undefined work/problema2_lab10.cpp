#include <iostream>
#include <stdio.h>
using namespace std;

void fibonaci(int n)

{int s1=1,s2=1,s;
cout<<s1<<' '<<s2<<' ';
    for(int i=1;i<=n-2;i++)
    {s=s1+s2;
        s1=s2;
        s2=s;
        cout<<s<<' ';

    }cout<<'\n';
}
int main()
{int n;
    for(int i=1;i<=4;i++)
    {printf("citeste valoarea pana la cat se va afisa:");
    cin>>n;
        fibonaci(n);
    }
}
