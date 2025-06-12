#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using  namespace std;

int main()
{

unsigned short n;
unsigned int m;
printf("citeste un numar pe 32 de biti: ");
scanf("%u",&m);
printf("citeste un numar pe 8 de biti: ");
scanf("%hu",&n);
for(int i=31;i>31-n;i--)
{
    if((1<<i)&m)
    {
        m=m<<1;
        m++;
    }
    else
    {
        m=m<<1;
    }

}
cout<<m;
}







