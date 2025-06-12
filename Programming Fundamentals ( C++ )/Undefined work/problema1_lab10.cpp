#include <iostream>
#include <stdio.h>
using namespace std;

void numerePanaLaN(int n)
{
    for(int i=1;i<=n;i++)cout<<i<<' ';
    cout<<'\n';
}
int main()
{int n;
    for(int i=1;i<=3;i++)
    {printf("citeste valoarea pana la cat se va afisa:");
    cin>>n;
        numerePanaLaN(n);
    }
}
