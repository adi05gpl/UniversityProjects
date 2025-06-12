#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int a[50],b[50];

int main()
{char a[52],b[52];
    printf("citeste a: ");
cin.get(a, 50);
cin.get();
printf("citeste b: ");
cin.get(b, 50);

for(int i=0;i<strlen(a);i++)
{
    for(int j=1;j<=(int)b[i]-48;j++)
    {
        cout<<a[i];
    }
}
}





