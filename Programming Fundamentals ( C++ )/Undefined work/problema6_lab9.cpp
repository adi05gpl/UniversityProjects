#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int a[50],b[50];

int main()
{char a[255],b[255],c[255];
    printf("citeste a: ");
cin.get(a, 255);
cin.get();
strcpy(b,a);
int s=0;
char aux;
char *pointerpoz=strtok(b," .!,;");
while(pointerpoz != NULL)
{
strcpy(c,a+s+strlen(pointerpoz));
for(int i=0;i<=(strlen(pointerpoz)-1)/2;i++)
{
    char aux =pointerpoz[i];
    pointerpoz[i]=pointerpoz[strlen(pointerpoz)-1-i];
    pointerpoz[strlen(pointerpoz)-1-i]=aux;
}

strcpy(a+s,pointerpoz);
strcpy(a+s+strlen(pointerpoz),c);
s = s+strlen(pointerpoz)+1;
 pointerpoz  = strtok(NULL,"?,.:- !");
}
puts(a);
}





