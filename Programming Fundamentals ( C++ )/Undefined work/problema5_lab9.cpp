#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int main()
{char a[255],b[255],c[255];
    printf("citeste a: ");
cin.get(a, 255);
cin.get();
strcpy(b,a);
char *pointerpoz=strtok(b," .!,;abcdefghijklmnoprsqzxuytrw");
int k=0;
while(pointerpoz != NULL)
{
    if(pointerpoz[0]>=48 && pointerpoz[0]<=57)
    {
         int x=atoi(pointerpoz),i;
         char n[255];
         for(i=0;i<x;i++)n[i]='*';
        n[i]='\0';
      char *poz=strchr(a,pointerpoz[0]);
      strcpy(c,a+(strlen(a)-strlen(poz))+strlen(pointerpoz));
      strcpy(a+(strlen(a)-strlen(poz)),n);
      strcpy(a+(strlen(a)-strlen(poz))+x,c);
    }
 pointerpoz = strtok(NULL," .!,;abcdefghijklmnoprsqzxuytrw");
}
 puts(a);
}
