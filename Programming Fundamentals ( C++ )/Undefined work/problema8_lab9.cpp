#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int main()
{ int i,j,k=0;
  int nrapar1[30],nrapar2[30];
  char text1[255],text2[255];
  char cuvinte1[30][50],cuvinte2[30][50];//matrice de caractere sau vector de cuvinte
  puts("dati textul 1 format din mai multe cuvinte");
  cin.get(text1,255);
  cin.get();
   puts("dati textul 2 format din mai multe cuvinte");
  cin.get(text2,255);
  cin.get();
  int k1=0,k2=0;
  char* pointerpoz1=strtok(text1," ?!,.;:-");//si space e delimitator
  while(pointerpoz1!=0){
  strcpy(cuvinte1[k1],pointerpoz1);
  k1++;
  pointerpoz1=strtok(NULL," ?,.!;:");//la apelul repetitiv se gasesc toate cuv pe rand din var text
  }

     char* pointerpoz2=strtok(text2," ?!,.;:-");
   while(pointerpoz2!=0){
  strcpy(cuvinte2[k2],pointerpoz2);
  k2++;
  pointerpoz2=strtok(NULL," ?,.!;:");//la apelul repetitiv se gasesc toate cuv pe rand din var text
  }
  for( i=0;i<30;i++){
  nrapar1[i]=1;
  nrapar2[i]=1;
  }
   for(i=0;i<k1;i++)
  for( j=0;j<k2;j++)
  {
      if(strcmp(cuvinte1[i],cuvinte2[j])==0 && nrapar2[j]==1){
    k=1;
  nrapar1[i]=255;
  nrapar2[j]=-255;
  }
  }
  if(k){


  puts("cuvintele comune sunt:");
  for( i=0;i<k1;i++)
    if (nrapar1[i]==255)
    puts(cuvinte1[i]);
  }else{printf("nu exista cuvinte comune");}




}
