#include <iostream>
#include <stdio.h>
using namespace std;
const double pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505;
int main()
{
int a,b,a1,b1;
float r;
printf("Citeste a=");
scanf("%d",&a);
printf("Citeste b=");
scanf("%d",&b);
a1=a;
b1=b;
printf("subpunctul a) \n");
int c,d,e,f;
a=a1;
c=a++;
printf("a=%d",a);
printf("\n");
printf("c=%d",c);
printf("\n");
a=a1;
d=++a;
printf("a=%d",a);
printf("\n");
printf("d=%d",d);
printf("\n");
f=a--;
printf("a=%d",a);
printf("\n");
printf("f=%d",f);
printf("\n");
a=a1;
e=--a;
printf("a=%d",a);
printf("\n");
printf("e=%d",e);
printf("\n");

a=a1;
b=b1;


printf("subpunctul b) \n");
b+=10;
cout<<"b + 10 ="<<b;
cout<<'\n';
b=b1;
b-=10;
cout<<"b - 10 ="<<b;
cout<<'\n';
b=b1;
b*=10;
cout<<"b * 10 ="<<b;
cout<<'\n';
b=b1;
r=(float)b/10;
cout<<"b / 10 ="<<(float)r;
cout<<'\n';

printf("subpunctul c) \n");
int cat,rest;
cout<<"citeste 2 numere\n";
cout<<"a=";
cin>>a;
cout<<"b=";
cin>>b;
rest=a%b;
cat=a/b;
cout<<"catul impartiri lui a la b ="<<cat<<'\n'<<"restul impartiri lui a la b ="<<rest;
cout<<'\n';

printf("subpunctul d) \n");
printf("\nvaloarea cu 3 zecimalea =%.3lf",pi);
printf("\nvaloarea cu 5 zecimalea =%.5lf",pi);
printf("\nvaloarea cu 10 zecimalea =%.10lf\n",pi);

printf("subpunctul e) \n");
int n1,n2;
cout<<"citeste 2 numere\n";
cout<<"n1=";
cin>>n1;
cout<<"n2=";
cin>>n2;
cout<<"Valoarea expresiei este ="<<n1*n1*n1-n2*n2-n1*n2+10;


}
