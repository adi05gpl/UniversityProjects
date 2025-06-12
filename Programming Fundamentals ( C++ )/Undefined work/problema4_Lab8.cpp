#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using  namespace std;

int main()
{

unsigned int n;
unsigned short m;
cout<<"citeste un nr pe 32 biti ";
cin>>n;
cout<<"citeste un nr pe 8 biti ";
cin>>m;

unsigned short masca=1;

 n=n|(1<<m);
 n=n&(~(1<<(31-m)));

 cout<<n;
}

