#include <iostream>
using namespace std;

int main()
{
    int n,i,v=0;
    cin>>n;
    for(i=1000;i<=9999;i++)
    {
        if(i%n==0)
        {
            v++;
            cout<<i<<' ';
        }
    }
cout<<"Numar total de numere = "<<v;
}
