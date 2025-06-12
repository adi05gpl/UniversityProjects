#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int aria(int n)
{
    return n*n;
}
int main()
{int n;
    for(int i=1;i<=3;i++)
    {
        printf("citeste latura:\n");
        cin>>n;
        cout<<aria(n)<<'\n';

    }
}


