#include<iostream>
#include<conio.h>
using namespace std;

struct NodLDI{
	int info;
    NodLDI* pred;
	NodLDI* succ;
};
//LIST=inserare_inceput_LSI(LIST,info_nou);
//inserare_inceput_LDI(FRONT,END,info_nou);
struct CAPETE {
	NodLDI* FRONT;
	NodLDI* END;

};
CAPETE inserare_inceput_LDI(CAPETE capete, int info_nou) {
	if (capete.FRONT == NULL&&capete.END == NULL)
	{
		NodLDI* nou = new NodLDI;
		nou->info = info_nou;
		nou->succ = nou->pred = NULL;
		capete.FRONT = capete.END = nou;
		
		return capete;//return front si end;
	}
	
	else
	{
		NodLDI* nou = new NodLDI;
		nou->info = info_nou;
		nou->succ = nou->pred = NULL;
		nou->succ = capete.FRONT;
		capete.FRONT->pred = nou;
		return capete;
	}
	return capete;
	//INSERARE INTERIOR
	//+
	//+
	//+
	//nou->succ=dupa->succ
	//nou->pred=dupa;
	//dupa->succ->pred=nou;
	//dupa->succ=nou;

}
/*CAPETE inserare_interior_LDI(NodLDI** adrFRONT, NodLDI** adrEND, int info_nou)
{
	if(capete.FRONT==NULL&&capete.END==NULL)
}*/
//void inserare_inceput(0xAB00AB00, 0xAAAA0000,100);
/*NodLDI* FRONT;
&FRONT adresa lui FRONT==>NodLDI** FRONT;*/

CAPETE inserare_sfarsit_LDI(CAPETE capete, int info_nou)
{
	if (capete.FRONT == NULL&&capete.END == NULL)
	{
		NodLDI* nou = new NodLDI;
		nou->info = info_nou;
		nou->succ = nou->pred = NULL;
		capete.FRONT = capete.END = nou;
		
		return capete;
	}
	
	else
	{
		NodLDI* nou = new NodLDI;
		capete.END->succ = nou;
		nou->pred = capete.END;
		nou->succ = NULL;
		capete.END = nou;
		nou->info = info_nou;
	}
	return capete;
}
NodLDI* cautareSTDR_LDI(CAPETE capete, int cheia_caut)
{
	NodLDI* temp = capete.FRONT;
	while (temp != NULL)
	{
		if (temp->info == cheia_caut)
			return temp;
		else
			temp = temp->succ;

	}
	
}
NodLDI* cautareDRST_LDI(CAPETE capete, int cheia_caut)
{
	NodLDI* temp = capete.END;
	while (temp != NULL)
	{
		if (temp->info == cheia_caut)
			return temp;
		else
			temp = temp->pred;

	}

}
CAPETE inserare_interior_LDI(CAPETE capete, int info_nou, int cheia_caut)
{
	if (capete.FRONT == NULL&&capete.END == NULL)
	{
		NodLDI* nou = new NodLDI;
		nou->info = info_nou;
		nou->succ = nou->pred = NULL;
		capete.FRONT = capete.END = nou;
		
		return capete;
	}
	
	else
	{
		NodLDI* dupa = cautareSTDR_LDI(capete,cheia_caut);
		if (capete.FRONT == capete.END)
		{
			inserare_sfarsit_LDI(capete, info_nou);
		}
		else
		{
			NodLDI* nou = new NodLDI;
			dupa->succ->pred = nou;
			nou->succ = dupa->succ;
			nou->pred = dupa;
			dupa->succ = nou;
			nou->info = info_nou;
		}
	}
	return capete;
}
CAPETE stergere_inceput_LDI(CAPETE capete)
{
	if (capete.FRONT == NULL)
		cout << "Eroare, lista este goala";
	else
	{
		NodLDI* salv = capete.FRONT;
		capete.FRONT = capete.FRONT->succ;
		capete.FRONT->pred = NULL;
		delete(salv);

	}
	return capete;
}
CAPETE stergere_sfarsit_LDI(CAPETE capete)
{
	if (capete.FRONT == NULL)
		cout << "Eroare, lista este goala";
	else
	{
		NodLDI* salv = capete.END;
		capete.END = capete.END->pred;
		capete.END->succ = NULL;
		delete(salv);
	}
	return capete;
}
CAPETE stergere_interior_LDI(CAPETE capete,int cheia_caut)
{
	
	NodLDI* dupa = cautareSTDR_LDI(capete, cheia_caut);
	if (capete.FRONT = NULL)
		cout << "Eroare,lista este goala";
	else
	{
		if (capete.FRONT == capete.END)
		{
			stergere_inceput_LDI(capete);
		}
		else
		{
			NodLDI* salv = dupa->succ;
			dupa->succ = salv->succ;
			salv->succ->pred = dupa;
			delete(salv);
		}
	}
	return capete;
}
//SUBPROGRAM PENTRU  STERGERE FIX ACEL ELEMENT
CAPETE stergere_inhterior_LDI(CAPETE capete, int info_sters)
{
	NodLDI* nodcautat = cautareSTDR_LDI(capete, info_sters);
	if (nodcautat == NULL)
		cout << "Eroare";
	else if (nodcautat->pred == NULL)//primul nod se sterge
		capete = stergere_inceput_LDI(capete);
	else if (nodcautat->succ == NULL)
		capete = stergere_sfarsit_LDI(capete);
	else
	{//stergere din interior
		NodLDI* dupa = nodcautat->pred;
		dupa->succ = dupa->succ->succ;
		dupa->succ->succ->pred = dupa;
	}
}
CAPETE traversareSTDR_LDI(CAPETE capete)
{
	NodLDI* temp = capete.FRONT;
	while (temp != NULL)
	{
		temp = temp->succ;
	}
	return capete;
}
CAPETE traversareDRST_LDI(CAPETE capete)
{
	NodLDI* temp = capete.END;
	while (temp != NULL)
	{
		temp = temp->pred;
	}
	return capete;
}
CAPETE actualizare_LDI(CAPETE capete,int cheia_caut,int info_modific)
{
	NodLDI* adr = cautareSTDR_LDI(capete, cheia_caut);
	if (adr == NULL)
	{
		cout << "Eroare,elementul nu a fost gasit";
	}
	else
		adr->info = info_modific;
	return capete;
}
CAPETE eliberare_LDI(CAPETE capete)
{
	while (capete.FRONT != NULL)
		stergere_sfarsit_LDI(capete);
	return capete;
}
CAPETE eliminare_elemente(CAPETE capete)
{
	int raspuns = 0;
	NodLDI* tmp1 = capete.FRONT;
	while (tmp1 != NULL)
	{
		NodLDI* tmp2 = tmp1->succ;
		while (tmp2 != NULL)
		{
			
			if(tmp1==tmp2)
				capete = stergere_interior_LDI(capete, tmp2->pred->info);
			tmp2 = tmp2->succ;

		}
		tmp1 = tmp1->succ;
	}
}
CAPETE adaugare_element_dupa_divizor(CAPETE capete, int elem)
{
	NodLDI* tmp = capete.FRONT;
	while (tmp != NULL)
	{
		if (elem%tmp->info == 0)
		{
			capete = inserare_interior_LDI(capete, elem, tmp->info);
		}
		tmp = tmp->succ;
	}
}
CAPETE ordine_crescatoare(CAPETE capete)
{
	NodLDI* tmp = capete.FRONT;
	int aux;
	while (tmp != NULL)
	{
		NodLDI* tmp2 = tmp;
		if (tmp2->info > tmp2->succ->info)
		{
			int aux = tmp2->info;
			tmp2->info = tmp2->succ->info;
			tmp2->succ->info = aux;
		}
		tmp = tmp->succ;
	}
}
CAPETE ordine_descrescatoare(CAPETE capete)
{
	NodLDI* tmp = capete.FRONT;
	int aux;
	while (tmp != NULL)
	{
		NodLDI* tmp2 = tmp;
		if (tmp2->info < tmp2->succ->info)
		{
			int aux = tmp2->info;
			tmp2->info = tmp2->succ->info;
			tmp2->succ->info = aux;
		}
		tmp = tmp->succ;
	}
}
int main()
{
	
	int meniu, submeniu;
	CAPETE capete;
	capete.FRONT = NULL;
	capete.END = NULL;
	do
	{
		cout << "0.Iesire din lista" << endl;
		cout << "1.Initializare lista" << endl;
		cout << "2.Inserare in lista" << endl;
		cout << "3.Stergere din lista" << endl;
		cout << "4.Cautare in lista" << endl;
		cout << "5.Traversare lista,afisare" << endl;
		cout << "6.Actualizare lista" << endl;
		cout << "7.Eliberare lista" << endl;
		cout << "8.Operatii extinse" << endl;
		cout << "Introduceti optiunea[0,8]:";
		cin >> meniu;
		switch (meniu)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			cout << "Initializarea listei" << endl;
			capete.FRONT = NULL;
			capete.END = NULL;

			break;
		}
		case 2:
		{
			do {
				cout << "Apasati Enter pentru a sterge ecranul" << endl;
				_getch();
				system("cls");
				cout << "Inserare in lista" << endl;
				cout << "0.Revenire in program principal" << endl;
				cout << "1.Inserare la inceput" << endl;
				cout << "2.Inserare la sfarsit" << endl;
				cout << "3.Inserare in interior" << endl;
				cout << "Introduceti optiunea[0,3]:" << endl;
				cin >> submeniu;
				switch (submeniu)
				{
				case 0:
				{
					break;
				}
				case 1:
				{
					cout << "Inserare la inceput" << endl;
					cout << "Introduceti info_nou" << endl;
					int info_nou;
					cin >> info_nou;
					capete = inserare_inceput_LDI(capete, info_nou);
					//inserare_inceput_LDI(&FRONT,&END,info_nou);
					break;
				}
				case 2:
				{
					cout << "Inserare la sfarsit";
					cout << "Introduceti info_nou" << endl;
					int info_nou;
					cin >> info_nou;
					capete = inserare_sfarsit_LDI(capete, info_nou);
					break;
				}
				case 3:
				{
					cout << "Inserare in interior";
					cout << "Introduceti info_nou" << endl;
					int info_nou;
					cin >> info_nou;
					cout << "Introduceti info_dupa:";
					int dupa;
					cin >> dupa;
					capete = inserare_interior_LDI(capete, info_nou,dupa);
					break;
				}
				default: cout << "Varianta invalida" << endl;

				}//sf. switch interior
			} while (submeniu != 0);//sf. while interior
			break;
		}
		case 3:
		{
			do {
				cout << "Apasati Enter pentru a sterge ecranul" << endl;
				_getch();
				system("cls");
				cout << "Stregere in lista" << endl;
				cout << "0.Revenire in program principal" << endl;
				cout << "1.Stergere la inceput" << endl;
				cout << "2.Stergere la sfarsit" << endl;
				cout << "3.Stergere in interior" << endl;
				cout << "Introduceti optiunea[0,3]:" << endl;
				cin >> submeniu;
				switch (submeniu)
				{
				case 0:
				{
					break;
				}
				case 1:
				{
					cout << "Stergere la inceput";
					capete = stergere_inceput_LDI(capete);
					break;
				}
				case 2:
				{
					cout << "Stergere la sfarsit";
					capete = stergere_sfarsit_LDI(capete);
					break;
				}
				case 3:
				{
					cout << "Stergere in interior" << endl;
					cout << "Introduceti elementul dupa care vreti sa se stearga:" << endl;
					int cheia_caut;
					cin >> cheia_caut;
					capete = stergere_interior_LDI(capete,cheia_caut);
					break;
				}
				default: cout << "Varianta invalida" << endl;

				}//sf. switch interior
			} while (submeniu != 0);//sf. while interior
			break;
		}
		case 4:
		{
			cout << "Cautare in lista" << endl;
			cout << "Introduceti info_cautat:";
			int info_caut;
			cin >> info_caut;
			NodLDI* nodgasit = cautareSTDR_LDI(capete, info_caut);
			if (nodgasit == NULL)
			{
				cout << "Nu am gasit info in lista";
			}
			else
				cout << "Nodul " << nodgasit->info << " este in lista";
			break;
		}
		case 5:
		{
			cout << "Traversare lista" << endl;
			traversareSTDR_LDI(capete);
			break;
		}
		case 6:
		{
			cout << "Actualizare lista" << endl;
			cout << "Introduceti cheia:" << endl;
			int cheia_caut;
			cin >> cheia_caut;
			cout << "Introduceti  info_modific";
			int info_modific;
			cin >> info_modific;
			capete = actualizare_LDI(capete, cheia_caut, info_modific);
			break;
		}
		case 7:
		{
			cout << "Eliberare lista" << endl;
			capete = eliberare_LDI(capete);
			break;
		}
		case 8:
		{
			cout << "Operatii extinse" << endl;
			cout << "1.Eliminarea elementelor care se repeta" << endl;
			cout << "2.Adaugarea unui element dupa fiecare divizor al sau" << endl;
			cout << "3.Ordonarea listei crescator" << endl;
			cout << "4.Ordonarea listei descrescator" << endl;
			cin >> submeniu;
			switch (submeniu)
			{
			case 1:
			{
				cout << "Eliminarea elementelor care se repeta:" << endl;
				capete = eliminare_elemente(capete);
				break;
			}
			case 2:
			{
				cout << "Adaugarea unui element dupa fiecare divizor al sau" << endl;
				cout << "Dati element" << endl;
				int elem;
				cin >> elem;
				capete = adaugare_element_dupa_divizor(capete, elem);
				break;
			}
			case 3:
			{
				cout << "Ordonarea listei crescator" << endl;
				capete = ordine_crescatoare(capete);
				break;
			}
			case 4:
			{
				capete = ordine_descrescatoare(capete);
				break;
			}
			}
		}
		default:cout << "Optiune gresita" << endl;
		}//sf. switch
		cout << "Apasati Enter pentru a sterge ecranul" << endl;
		_getch();
		system("cls");
	} while (meniu != 0);
	//_getch();
	return 0;

}