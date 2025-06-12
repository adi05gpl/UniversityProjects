#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct NodLDI {
	string nume;
	string prenume;
	string serieBuletin;
	NodLDI* pred;
	NodLDI* succ;
};
struct CoadaDinamic {
	NodLDI* FRONT;
	NodLDI* END;
};
struct CoadaStatic {
	string* v;
	int FRONT;
	int END;
	int MAX;
};
CoadaDinamic Reset_Queue_Dinamic(CoadaDinamic coadaD)
{
	coadaD.FRONT = NULL;
	coadaD.END = NULL;
	return coadaD;
}
CoadaDinamic EnQueue_Dinamic(CoadaDinamic coadaD, string nume_nou,string prenume_nou, string serie_nou)
{
	{
		if (coadaD.FRONT == NULL&&coadaD.END == NULL)
		{
			NodLDI* nou = new NodLDI;
			nou->nume = nume_nou;
			nou->prenume = prenume_nou;
			nou->serieBuletin = serie_nou;
			nou->succ = nou->pred = NULL;
			coadaD.FRONT = coadaD.END = nou;

			return coadaD;
		}

		else
		{
			NodLDI* nou = new NodLDI;
			coadaD.END->succ = nou;
			nou->pred = coadaD.END;
			nou->succ = NULL;
			coadaD.END = nou;
			nou->nume = nume_nou;
			nou->prenume = prenume_nou;
			nou->serieBuletin = serie_nou;
		}
		return coadaD;
	}
}
bool Empty_Queue_Dinamic(CoadaDinamic coadaD)
{
	if (coadaD.FRONT == NULL)
		return true;
	else
		return false;
}
CoadaDinamic DeQueue_Dinamic(CoadaDinamic coadaD)
{
	if (Empty_Queue_Dinamic(coadaD))
		cout << "EROARE,LISTA ESTE GOALA";
	else
	{
		string salvareN = coadaD.FRONT->nume;
		string salvareP = coadaD.FRONT->prenume;
		string salavareS = coadaD.FRONT->serieBuletin;
		if (coadaD.FRONT == NULL)
			cout << "Eroare, lista este goala";
		else
		{
			NodLDI* salv = coadaD.FRONT;
			coadaD.FRONT = coadaD.FRONT->succ;
			coadaD.FRONT->pred = NULL;
			delete(salv);

		}
		return coadaD;
	}
}
bool emptyQueue_S(CoadaStatic coadaS)
{
	return coadaS.FRONT == coadaS.END;
}
bool FullQueue_S(CoadaStatic coadaS)
{
	return coadaS.END == coadaS.MAX;//coada este plina
}
CoadaStatic EnQueue_Static(CoadaStatic coadaS, string nume_nou,string prenume_nou,string serie_nou)
{
	if (FullQueue_S(coadaS) == false)
	{
		coadaS.v[coadaS.END] = nume_nou;
		coadaS.v[coadaS.END] = prenume_nou;
		coadaS.v[coadaS.END] = serie_nou;
		coadaS.END++;
	}
	return coadaS;
}
CoadaStatic initializare_CoadaS(CoadaStatic coadaS)
{
	cout << "Introduceti MAX:" << endl;
	cin >> coadaS.MAX;
	coadaS.v = new string[coadaS.MAX];
	coadaS.FRONT = coadaS.END = 0;
	return coadaS;
}
CoadaStatic DeQueue_S(CoadaStatic coadaS, string* adrelScos)
{
	if (emptyQueue_S(coadaS) == true)
		*adrelScos = -1000000;
	else
	{
		*adrelScos = coadaS.v[coadaS.FRONT];
		coadaS.FRONT++;
	}
	return coadaS;
}
int main()
{
	int meniu, submeniu, meniu1;
	CoadaStatic coadaS;
	CoadaDinamic coadaD;
	cout << "1.Coada statica" << endl;
	cout << "2.Coada dinamica" << endl;
	cin >> meniu1;
	switch (meniu1)
	{
	case 1:
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
				coadaS = initializare_CoadaS(coadaS);
				break;
			}
			case 2:
			{
				cout << "ENQUEUE" << endl;
				cout << "Introduceti nume_nou" << endl;
				string nume_nou;
				string prenume_nou;
				string serie_nou;
				cin >> nume_nou;
				cout << "Introduceti prenume_nou" << endl;
				cin >> prenume_nou;
				cout << "Introduceti serie_nou" << endl;
				cin >> serie_nou;
				coadaS = EnQueue_Static(coadaS, nume_nou, prenume_nou, serie_nou);
				break;
			}
			case 3:
			{
				cout << "DEQUEUE" << endl;
				string element;
				coadaS = DeQueue_S(coadaS, &element);
				break;
			}
			case 4:
			{
				cout << "Afisare FRONT si END" << endl;
				cout << coadaS.FRONT << "si " << coadaS.END;
				break;
			}
			case 5:
			{
				cout << "Afisare" << endl;
				for (int i = 0; i < coadaS.END; i++)
					cout << coadaS.v[i] << " " << endl;
				break;
			}
			default: cout << "OPTIUNE INVALIDA" << endl;
			}
		} while (meniu != 0);
		break;

	case 2:
	{
		do {
			cout << "0.Iesire din program" << endl;
			cout << "1.Initializare coada" << endl;
			cout << "2.Adaugare element in coada" << endl;
			cout << "3.Stergere element din coada" << endl;
			cout << "Introduceti optiunea [0-3]:" << endl;
			cin >> meniu;
			switch (meniu)
			{
			case 0:
				break;
			case 1:
			{
				cout << "Initializare coada" << endl;
				coadaD = Reset_Queue_Dinamic(coadaD);
				break;
			}
			case 2:
			{
				cout << "Adaugare element in coada" << endl;
				cout << "Introduceti nume_nou ce urmeaza a fi adaugat" << endl;
				string nume_nou;
				cin >> nume_nou;
				string prenume_nou;
				string serie_nou;
				cout << "Introduceti prenume_nou ce urmeaza a fi adaugat" << endl;
				cin >> prenume_nou;
				cout << "Introduceti serie_nou ce urmeaza a fi adaugat" << endl;
				coadaD = EnQueue_Dinamic(coadaD, nume_nou, prenume_nou, serie_nou);
				break;
			}
			case 3:
			{
				cout << "Stergere element din coada" << endl;
				coadaD = DeQueue_Dinamic(coadaD);
				break;
			}
			default:
				cout << "OPTIUNE INVALIDA" << endl;
				break;
			}
		} while (meniu != 0);
	}
	}


	_getch();
	return 0;
}
