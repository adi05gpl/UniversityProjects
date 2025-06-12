#include <iostream>
using namespace std;

int main()
{
    int n,i,s=0;
    long p=1;
    cin>>n;
    for(i=0;i<=n;i++)s=s+i;
     for(i=1;i<=n;i++)p*=i;

     cout<< "\nSuma ="<<s;
    cout<< "\nProdus ="<<p;
}
