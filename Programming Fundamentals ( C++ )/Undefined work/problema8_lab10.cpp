#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[255],v[]="aeiou";
int nrVoc(char s[])
{int n=0,i;
for(i=0;i<=strlen(s)-1;i++){
    if(strchr(v,s[i])){
       n++;
        }
}

return n;
}
int main()
{
    for(int i=1;i<=3;i++)
    {cout<<"citeste s: ";
    cin.get(s,255);
    cin.get();
    cout<<"numarul de vocale din text este: ";
    cout<<nrVoc(s);
    cout<<'\n';


    }
}




