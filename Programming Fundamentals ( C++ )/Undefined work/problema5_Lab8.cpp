#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using  namespace std;

int main()
{

unsigned short a;
unsigned short i,s;
cin>>a;
s=a&(1<<15);
i=a&(1<<0);
cout<<'\n'<<s<<' '<<i<<'\n';
if(s==0)
{
    a=a&(~s);
}
else
{
a=a|s;

}

if(i==0)
{
    a=a&(~i<<15);
}
else
{
a=a|(i<<15);

}
cout<<a;
}






