#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void citireM(int n,int m,int**  a)
{
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>a[i][j];

}
void afisareM(int n,int m,int** a)
{
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cout<<a[i][j]<<' ';
    cout<<'\n';
    }
}
void maximulM(int** a,int n,int m,int &maxi,int &pozi,int &pozj)
{
     maxi=a[0][0];
pozi=0;
pozj=0;
       for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maxi<a[i][j])
            {
                maxi=a[i][j];
                pozi=i;
                pozj=j;
            }
        }
    }
}
int main()
{int n,m,i;
int maxi,pozi,pozj;
cin>>n>>m;
int** a=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)a[i]=(int*)malloc(m*sizeof(int));
citireM(n,m,a);
afisareM(n,m,a);
maximulM(a,n,m,maxi,pozi,pozj);
cout<<maxi<<' '<<pozi<<' '<<pozj;
for(int i=0;i<n;i++)free(a[i]);
free(a);
}




