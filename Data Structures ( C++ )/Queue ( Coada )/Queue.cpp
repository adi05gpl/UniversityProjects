#include<iostream>
#include<conio.h>
using namespace std;
struct CoadaStatic {
	int* v;
	int FRONT;
	int END;
	int MAX;
};
bool emptyQueue_S(CoadaStatic coada)
{
	return coada.FRONT == coada.END;
}
bool FullQueue_S(CoadaStatic coada)
{
	return coada.END == coada.MAX;
}
CoadaStatic EnQueue_Static(CoadaStatic coada, int info_nou)
{
	if (FullQueue_S(coada) == false)
	{
		coada.v[coada.END] = info_nou;
		coada.END++;
	}
	return coada;
}
CoadaStatic initializare_CoadaS(CoadaStatic coada)
{
	cout << "Introduceti MAX:" << endl;
	cin >> coada.MAX;
	coada.v = new int[coada.MAX];
	coada.FRONT = coada.END = 0;
	return coada;
}
CoadaStatic DeQueue_S(CoadaStatic coada, int* adrelScos)
{
	if (emptyQueue_S(coada) == true)
		*adrelScos = -1000000;
	else
	{
		*adrelScos = coada.v[coada.FRONT];
		coada.FRONT++;
	}
	return coada;
}

int main()
{
	int meniu, submeniu;
	CoadaStatic coada;
	do {
		cout << "1.Initializare" << endl;
		cout << "2.EnQueue" << endl;
		cout << "3.DeQueue" << endl;
		cout << "4.FRONT,END" << endl;
		cout << "5.Afisare" << endl;
		cout << "0.Iesire din program" << endl;
		cin >> meniu;
		switch (meniu)
		{
		case 0:
			break;
		case 1:
		{
			cout << "INITILIZARE" << endl;
			coada = initializare_CoadaS(coada);
			break;
		}
		case 2:
		{
			cout << "ENQUEUE" << endl;
			cout << "Introduceti info_nou" << endl;
			int info_nou;
			cin >> info_nou;
			coada = EnQueue_Static(coada, info_nou);
			break;
		}
		case 3:
		{
			cout << "DEQUEUE" << endl;
			int element;
			coada = DeQueue_S(coada, &element);
			break;
		}
		case 4:
		{
			cout << "Afisare FRONT si END" << endl;
			cout << coada.FRONT << "si " << coada.END;
			break;
		}
		case 5:
		{
			cout << "Afisare" << endl;
			for (int i = 0;i < coada.END;i++)
				cout << coada.v[i] << " " << endl;
			break;
		}
		default: cout << "OPTIUNE INVALIDA" << endl;
		}
	} while (meniu != 0);
	_getch();
	return 0;
}//coada=initializare_CoadaS(coada) apel
/*LSI: inserare_la_sf(LIST,info,&END);
LDI:
struct CAPETE{
NodLDI* FRONT;
NodLDI*END;
};
apel: Coada_D EnQueue(CoadaD coada, int info){
coada=inserare_sf_LDI(coada,info);
return coada;
//stiva statica extensibila:
daca stiva devine plina
MAX=3;
7 3 5 stiva e plina;
==>DORITI sa extindeti stiva?
alocare alt vector ,copiere toate elementele din stivab anterioara,....
dupa copiere v=w; free(W);
maxplus=10;
int* w=new int[MAX+maxplus];
for(int i=0;i<stiva.MAX;i++)
      w[i]=stiva.v[i];
delete stiva.v;
stiva.v=w;
}*/