#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int x,y,z,a;
    double v=0;
    printf("valoarea lui x=");
    scanf("%d",&x);
    printf("valoarea lui y=");
    scanf("%d",&y);
    printf("valoarea lui z=");
    scanf("%d",&z);
 //cin>>x>>y>>z;
v=sqrt((double)x*x+(double)y*y+(double)z*z);
printf("a)\n");
printf("radical din x^2+y^2+z^2 =%f",v);
printf("\n");
printf("b)\n");
//cout<<exp(x*log(y*z));
v=exp((double)x*log(y*z));
printf("exp(x*ln(y*z))=%f",v);
printf("\nc)\n");

a=abs(x-y-z);
printf("|x-y-z|=%d",a);
printf("\nd)\n");
v=pow((double)(x+y+z),2);
printf("(x+y+z)^2 =%f",v);
printf("\ne)\n");
a=x%y;
printf("restul impartiri lui x la y = %d",a);
printf("\nf)\n");
a=x/z;
printf("valoare intreaga a impartiri lui x la z = %d",a);


}
