#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using  namespace std;

int main()
{

short a;
cout<<"citeste un nr pe 8 biti ";
cin>>a;

 unsigned char masca=1;
 masca = masca<<2;
if(masca&a)
{
    a=a|(1<<5);
}else{

a=a&(~(1<<7));
}
printf("%d ",a);
}

