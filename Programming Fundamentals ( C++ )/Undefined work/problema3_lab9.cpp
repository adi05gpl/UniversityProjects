#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int a[50],b[50];
int verif(char a[60])
{
    for(int i=0;i<strlen(a);i++)
    {
        if(strchr("1234567890",a[i])==0)
        {
            return 0;
        }
    }
    return 1;
}
int sum(char a,char b,int &t)
{
    int x,y;
    x=(int)a-48;
    y=(int)b-48;

    int s=x+y+t;
    t=s/10;
    s=s%10;

    return (char)(s+48);
}

int main()
{char a[52],b[52];
    printf("citeste a: ");
cin.get(a, 50);
cin.get();
printf("citeste b: ");
cin.get(b, 50);

int n,m;
n=verif(a);
m=verif(b);
if(n&&m){
int x=strlen(a)-1,y=strlen(b)-1,i,j;
int t=0;
if(x>=y)
{
    while(y>=0)
    {
        a[x]=sum(a[x],b[y],t);
        x--;
        y--;
    }
    while(x>=0 && t!=0)
    {
        a[x]=sum(a[x],'0',t);
        x--;
    }
    if(t!=1) for(i=0;i<=strlen(a)-1;i++)cout<<a[i];
    else
    {
        cout<<t;
        for(i=0;i<=strlen(a)-1;i++)cout<<a[i];
    }
}
else
{
     while(x>=0)
    {
        b[y]=sum(a[x],b[y],t);
        x--;
        y--;
    }
    while(y>=0 && t!=0)
    {
        b[y]=sum(b[y],'0',t);
        y--;
    }
    if(t!=1) for(i=0;i<=strlen(b)-1;i++)cout<<b[i];
    else
    {
        cout<<t;
        for(i=0;i<=strlen(b)-1;i++)cout<<b[i];
    }

}
}
else
{
    cout<<"te rog introdu doar cifre data viitoare";
}
}





