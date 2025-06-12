#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    unsigned int a,b,c;
    printf("Citeste valoarea catetei 1\n");
    scanf("%d",&a);
      printf("Citeste valoarea catetei 2\n");
      scanf("%d",&b);
        printf("Citeste valoarea ipotenuzei\n");
        scanf("%d",&c);
if(a+b>c && a+c>b && b+c>a){
        if((c*c)==(a*a+b*b))
        {

                printf("triunghiul este dreptunghic");

        }
        else if(a==b && a==c)
        {
            printf("triunghiul este echilateral");
        }
        else if(a==b ||a==c || b==c)
        {
            printf("triunghiul este isoscel");
        }
        else
        {
        printf("triunghiul este unul oarecare");
        }
}else
{
          printf("nu este un triunghi");
}
}

