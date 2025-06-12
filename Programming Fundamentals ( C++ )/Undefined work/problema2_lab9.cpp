#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int a[100];
void low(char &a)
{
    if(a<=90 && a>=65)
    {
        a=a+('a'-'A');
    }
}
int main()
{
    char text[255];
    cin.get(text, 255);
   for (int i=0; i<=strlen(text);i++)
    low(text[i]);
int i=0,j=strlen(text)-1,ok=1;
while(i<=j && ok==1)
{
    while(i==' ')i++;
    while(j==' ')j--;
    if(text[i]!=text[j])ok=0;
    i++;
    j--;
}
if(ok==1)cout<<"palindrom";
    else cout<<"nu este palindrom";
}





