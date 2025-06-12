#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
cout<<"Laboratorul de programare";
getch();
system("CLS");
cout<<'\a';
cout<<'\n'<<' '<<"Laboratorul de programare";
getch();
for(int i=2;i<=4;i++)
{
    system("CLS");
    cout<<'\a';
    for(int j=1;j<=i;j++)
    {
        cout<<'\n';
    }
     for(int j=1;j<=i;j++)
    {
        cout<<' ';
    }

        cout<<"Laboratorul de programare";

     getch();
}
getch();
}

