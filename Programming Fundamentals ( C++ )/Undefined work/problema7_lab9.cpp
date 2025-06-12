#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using  namespace std;

int a[50],b[50];

int main()
{ int i,j;
  int nrapar[30];
  char text[255];
  char cuvinte[30][50];//matrice de caractere sau vector de cuvinte
  puts("dati textul format din mai multe cuvinte");
  cin.get(text,255);
  cin.get();
  int k=0;
  char* pointerpoz=strtok(text," ?!,.;:-");//si space e delimitator
  while(pointerpoz!=0){
  strcpy(cuvinte[k],pointerpoz);
  k++;
  pointerpoz=strtok(NULL," ?,.!;:");//la apelul repetitiv se gasesc toate cuv pe rand din var text
  }
  for( i=0;i<30;i++){
  nrapar[i]=1;
  }
   for(i=0;i<k;i++)
  for( j=i+1;j<k;j++)
  {
      if(strcmp(cuvinte[i],cuvinte[j])==0){

  nrapar[i]++;
  nrapar[j]=-255;
  }
  }
  puts("cuvintele frazei:");
  for( i=0;i<k;i++)if (nrapar[i]>=1)
    puts(cuvinte[i]);



  for( i=0;i<k;i++){
  if (nrapar[i]>=1){
        printf("cuvantul %s apare de %d ori\n",cuvinte[i],nrapar[i]);
  }
  }

}
/*
 ex7:
	  char sir[250];
	  char subsir[100];
	  puts("dati text(o linie): ");
	  gets_s(sir,250);//gets pt codeblocks
	  puts("dati subsir(un cuvant)");
	  gets_s(subsir,100);
	  char* pointerpoz= strstr(sir,subsir);
	  while(pointerpoz!=0){
	       int poz=pointerpoz-sir;
		   prinf("cuvantul %s apare pe pozitia %d\n",subsir,pointerpoz);
		   ponterpoz=strstr(sir+poz+strlen(subsir),subsir);
	  }
  char text[255];
  char cuvinte[30][50];//matrice de caractere sau vector de cuvinte
  puts("dati textul format din mai multe cuvinte");
  gets_s(text,255);
  int k=0;
  char* pointerpoz=strtok(text," ?!,.;:-");//si space e delimitator
  while(pointerpoz!=0){
  strcpy(cuv[k],pointerpoz);
  k++;
  pointerpoz=strtok(NULL," ?,.!;:");//la apelul repetitiv se gasesc toate cuv pe rand din var text
  }
  puts("cuvintele frazei:");
  for(int i=0;j<k;i++) puts(cuvinte[i]);
  int nrapar[30];
  for(int i=0;i<30;i++){
  nrapar[i]=1;}
  for(int j=i+1;j<k;j++)
  {if(strcmp(cuvinte[i],cuvinte[j])==0){
  nrapar[i]++;
  nrapar[j]=-1;}}
  for(int i=0;i<k;i++){
  if (nrapar[i]>=1){prinf("cuvantul %s apare de %d ori\n",cuvinte[i],nraparitii[i]);}
  }


*/

