#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int piramida(int n)
{
    for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=i;j++)
        {
        cout<<j<<' ';
        }
        cout<<'\n';
    }

}
int main()
{int n;
    for(int i=1;i<=3;i++)
    {cout<<"citeste n: ";
    cin>>n;
    piramida(n);

    }
}



