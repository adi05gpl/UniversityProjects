#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    char a,x,y,z,d,b,c;


cout<<"\nprint/scan";
printf("\nciteste a=");
scanf("\na=%c",&a);
fflush(stdin);
printf("\na=%c",a);

cout<<"\ncout/cin";
cout<<"\na=";
cin>>a;
d=a-32;
b=a-1;
c=a+1;
cout<<'\n'<<(char)(d);
cout<<'\n'<<(char)(b);
cout<<'\n'<<(char)(c);
cout<<"\na=";
fflush(stdin);
cin.get(a);
cout.put(a);
fflush(stdin);
}

