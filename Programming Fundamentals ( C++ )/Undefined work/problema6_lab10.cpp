#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int ecGr2(int a,int b,int c)
{int delta;
    float x1,x2;
    if(a==0)
    {
        cout<<"Functie este  de gradul 1,cu x="<<-b/c;
        return 0;
    }
delta=b*b-4*a*c;

    if(delta>=0)
    {
     if(delta==0)
     {cout<<"x1=x2="<<-b/(2*a);
     return 0;
     }
     else
     {
         x1=(-b+sqrt(delta))/(2*a);
         x2=(-b-sqrt(delta))/(2*a);
         cout<<"x1="<<x1<<'\n'<<"x2="<<x2;
         return 0;
     }
    }
    else
    {
    cout<<"nu exista radacini reale";
    return 0;
    }
}
int main()
{int a,b,c;
    for(int i=1;i<=3;i++)
    {
        printf("\nciteste cei 3 parametri ai functiei:\n");
        cout<<"a=";
        cin>>a;
        cout<<"b=";
        cin>>b;
        cout<<"c=";
        cin>>c;
        ecGr2(a,b,c);
    }
}


