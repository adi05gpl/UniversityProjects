#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using  namespace std;

int main()
{

unsigned int a;
cout<<"citeste un nr pe 8 biti ";
cin>>a;

 unsigned long masca=1;
printf("Forma binara este \n");
 for(int k=31;k>=0;k--)
{
    masca=(1<<k);
    unsigned int bit=(a&masca);
    if(bit==0)cout<<'0';
    else cout<<'1';
}

}





