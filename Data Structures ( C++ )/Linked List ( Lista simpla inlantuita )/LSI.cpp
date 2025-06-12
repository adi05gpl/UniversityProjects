#include<iostream>
#include<conio.h>
using namespace std;

struct NodLSI
{
	int info;
	
	NodLSI* succ;

};
NodLSI* inserare_inceput_LSI(NodLSI* LIST, int info_nou)
{
	
	if (LIST == NULL)
	{
		NodLSI* nou = new NodLSI;
		nou->info = info_nou;
		nou->succ = NULL;
		LIST = nou;
		return LIST;
	}
	
	else
	{
		NodLSI* nou = new NodLSI;
		nou->info = info_nou;
		nou->succ = NULL;
		nou->succ = LIST;
		LIST = nou;
	}

}



NodLSI* cautare_LSI(NodLSI* LIST, int info_caut) 
{
	NodLSI* tmp = LIST;
	while (tmp != NULL)
	{
		if (tmp->info == info_caut)
			return tmp;
		else
			tmp = tmp->succ;
	}
	return NULL;
}
NodLSI* inserare_interior_LSI(NodLSI* LIST, int info_nou, int info_caut)
{
	NodLSI* nou = new NodLSI;
	nou->info = info_nou;
	
	NodLSI* dupa = cautare_LSI(LIST, info_caut);
	if (dupa == NULL) 
	{
		cout << "Elementul dupa care s-ar dori inserarea nu exista";
		return LIST;
	}
	else
	{
		nou->succ = dupa->succ;
		dupa->succ = nou;
		
		return LIST;
	}


}
void afisare_traversare_LSI(NodLSI* LIST)
{
	NodLSI* tmp = LIST;
	while (tmp != NULL)
	{
		cout << tmp->info << " ";
		tmp = tmp->succ;
	}
}
NodLSI* stergere_sfarsit_LSI(NodLSI* LIST)
{
	NodLSI* tmp = NULL;
	
	while (tmp->succ->succ!=NULL)
	{
		tmp = tmp->succ;

	}
	NodLSI* penultim = tmp;
	NodLSI* salv = penultim->succ;
	delete salv;
	penultim->succ = NULL;
	return LIST;

}
NodLSI* inserare_sfarsit_LSI(NodLSI* LIST, int info_nou)
{
	NodLSI* temp;
	if (LIST == NULL)
	{
		NodLSI* nou = new NodLSI;
		LIST = nou;
		LIST->succ = NULL;
		LIST->info = info_nou;
	}
	else
	{
		temp = LIST;
		while (temp->succ != NULL)
		{
			temp = temp->succ;
		}
		NodLSI* ultim = temp;
		NodLSI* nou = new NodLSI;
		ultim->succ = nou;
		nou->succ = NULL;
		nou->info = info_nou;
		return LIST;
	}
}
NodLSI* stergere_inceput_LSI(NodLSI* LIST)
{
	if (LIST == NULL)
	{
		cout << "LISTA ESTE GOALA";
	}
	NodLSI* adr = LIST;
	LIST = LIST->succ;
	delete(adr);
	return LIST;
}
NodLSI* stergere_interior_LSI(NodLSI* LIST)
{
	NodLSI* adr;
	NodLSI* dupa;
	if (LIST == NULL)
	{
		cout << "LISTA ESTE GOALA";
	}
	else
	{
		if (LIST->succ == NULL)
		{
			delete(LIST);
			LIST = NULL;
		}
		else
		{
			adr = dupa->succ;
			dupa->succ = adr->succ;
			delete(adr);
		}
	}
	return LIST;
}
NodLSI* actualizare_LSI(NodLSI* LIST, int cheia_caut, int info_modific)
{
	NodLSI* adr = cautare_LSI(LIST, cheia_caut);
	if (adr == NULL)
		cout << "LISTA ESTE GOALA";
	else
		adr->info = info_modific;
	return LIST;
}
NodLSI* eliberare_LSI(NodLSI* LIST)
{
	while (LIST != NULL)
	{
		stergere_sfarsit_LSI(LIST);
	}
	return LIST;
}

int main()
{
	NodLSI* LIST=NULL;
	int meniu, submeniu;

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
		cout << "Introduceti optiunea[0,7]:";
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
			LIST = NULL;

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
					LIST = inserare_inceput_LSI(LIST, info_nou);
					break;
				}
				case 2:
				{
					cout << "Inserare la sfarsit";
					cout << "Introduceti info_nou" << endl;
					int info_nou;
					cin >> info_nou;
					LIST = inserare_sfarsit_LSI(LIST, info_nou);
					break;
				}
				case 3:
				{
					cout << "Inserare in interior";
					cout << "Introduceti info_nou" << endl;
					int info_nou;
					cin >> info_nou;
					cout << "Introduceti info_dupa:";
					int info_dupa;
					cin >> info_dupa;
					LIST = inserare_interior_LSI(LIST, info_nou,info_dupa);
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
					LIST = stergere_inceput_LSI(LIST);
					break;
				}
				case 2:
				{
					cout << "Stergere la sfarsit";
					LIST = stergere_sfarsit_LSI(LIST);
					break;
				}
				case 3:
				{
					cout << "Stergere in interior";
					LIST = stergere_interior_LSI(LIST);
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
			NodLSI* nodgasit = cautare_LSI(LIST, info_caut);
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
			afisare_traversare_LSI(LIST);
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
			LIST=actualizare_LSI(LIST, cheia_caut, info_modific);
			break;
		}
		case 7:
		{
			cout << "Eliberare lista" << endl;
			LIST = eliberare_LSI(LIST);
			break;
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