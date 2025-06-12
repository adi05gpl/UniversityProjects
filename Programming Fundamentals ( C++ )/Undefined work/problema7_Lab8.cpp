#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using  namespace std;

int main()
{

unsigned short n;
int s=0;
cin>>n;
for(int i=0;i<8;i++)
if(1<<i & n)s++;
cout<<s;
}







