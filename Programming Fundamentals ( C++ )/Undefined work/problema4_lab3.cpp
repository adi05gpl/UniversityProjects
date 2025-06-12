#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{int n1,a;
double n2,b;
printf("Valoare variabilei n1 este ");
scanf("%d",&n1);
printf("\nValoare variabilei n2 este ");
scanf("%lf",&n2);
a = !(n1 == 2);
printf("Valoarea de adevar a expresiei neg(n1==2) este %d",a);
a = (n2 != 5);
printf("\nValoarea de adevar a expresiei n2 != 5 este %d",a);
a = (n1>2) && (n2 <=5.5);
printf("\nValoarea de adevar a expresiei (n1>2) && (n2 <=5.5) este %d",a);
a= (n1>=0)||(n2>=0);
printf("\nValoarea de adevar a expresiei (n1>=0) || (n2>=0) este %d",a);
b= (pow((double)n1,3)-pow(n2,2)-n1*n2+10);
printf("\nValoare expresiei n1^3-n2^2-n1*n2+10 este %lf", b);
b=pow((double)n1,n2);
printf("\nValoare expresiei n1^n2 este %lf", b);
b=n1/n2;
printf("\nValoare expresiei n1/n2 este %lf", b);
a=n1/(int)n2;
printf("\nCatul impartiri lui n1 la n2 este %d", a);
a=n1%(int)n2;
printf("\nRestul impartiri lui n1 la n2 este %d", a);
}

