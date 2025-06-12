#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;
/*#include <string.h>
//pt ex7 char* pointerPoz = strstr(text, subs);
char text[255];
gets_s(text, 255); cin.get?
char subs[30];
gets_s(subs, 30);
while(pointerpoz != NULL)
{
int poz=ointerpoz-text;
 poinerpoz = strstr()text+poz+strlen(subs),subs);
}
//sarim la liatera l text + poz
//text + poz+strlen(subsir) u dc limbajul
*/
/*#include <string.h>
###Tokenizare

strtok(text," ");
curs 8 pg 26;
char text[255];
char cuvinte[30][50]; /matrice de caractere sau vector de cuvinte
puts("Dati textul");
gets_s(text, 255); cin.get?
char* pointerpoz=strtok(text,"?,.:- !");
int k=0;
while(pointerpoz != NULL)
{
strcpy(cuvinte[k],pointerpoz);

k++;
 poinerpoz = strtok(NULL,"?,.:- !");
}
puts("cuvintele frazei:");
for(int i=0;i<k;i++)
{
puts(cuvinte[i]);
}
//iau primul cuvant apoi trec prin lista;
int nrapariti[30];
for(int i=0;i<k;i++)
    for(int j=i+1;j<k;j++)
{
if(strcmp(cuvinte[i],cuvinte[j])==0)
{
nrapariti[i]++;
nrapariti[j]=-1;
}
}

printf
*/
//65-90
int a[100];
int main()
{
    char text[255];
    cin.get(text, 255);
    for(int i=0;i<=strlen(text);i++)
    {
        if(text[i]<=90 && text[i]>=65)
        {
            a[text[i]]++;
        }
        else if(text[i]<=122 && text[i]>=97)
        {
            a[text[i]]++;
        }
    }
for(int i=65;i<=122;i++)
{
    if(a[i]>0)
    printf("caracterul ASCII %d (%c) apare de %d ori in text\n",i,i,a[i]);
}

}
