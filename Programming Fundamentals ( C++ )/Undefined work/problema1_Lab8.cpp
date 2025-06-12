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

 unsigned char bit=(1<<3)&a;
 bit=bit>>3;
printf("valoarea bitului al 3-lea este  %d\n",bit);
 bit=1&a;
 printf("valoarea bitului de paritate este  %d\n",bit);
short a2 =a;
a=a&(~(1<<2));
 printf("valoarea nr dupa resetarea bitului de pe pozitia a doua este %d\n",a);
 a2=a2|(1<<4);
  printf("valoarea nr dupa setearea bitului de pe pozitia a 4-a este %d",a2);

}




