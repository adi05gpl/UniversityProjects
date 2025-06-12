#include<iostream>
#include<conio.h>
using namespace std;
struct NodLSI{
    int info;
    NodLSI* succ;
};
struct StackDinamic {
	NodLSI* TOP;
	NodLSI* LIST;
};

StackDinamic Reset_StackDinamic(StackDinamic stiva, int info)
{
	stiva.LIST = NULL;
	stiva.TOP = NULL;
	return stiva;
}
StackDinamic Push_StackDinamic(StackDinamic stiva, int info_nou)
{
	NodLSI* temp;
	if (stiva.LIST == NULL)
	{
		NodLSI* nou = new NodLSI;
		stiva.LIST = nou;
		stiva.LIST->succ = NULL;
		stiva.LIST->info = info_nou;
	}
	else
	{
		temp = stiva.LIST;
		while (temp->succ != NULL)
		{
			temp = temp->succ;
		}
		NodLSI* ultim = temp;
		NodLSI* nou = new NodLSI;
		ultim->succ = nou;
		nou->succ = NULL;
		nou->info = info_nou;
		stiva.TOP = nou;
		return stiva;
	}
}
bool EmptyStack(StackDinamic stiva)
{
	if (stiva.TOP == NULL)
	{
		return true;
	}
	else
		return false;
}
int Pop_StackDinamic(StackDinamic stiva)
{
	if (EmptyStack(stiva))
		cout << "Eroare";
	else
	{
		NodLSI* tmp = NULL;

		while (tmp->succ->succ != NULL)
		{
			tmp = tmp->succ;

		}
		NodLSI* penultim = tmp;
		NodLSI* salv = penultim->succ;
		int elem_sters = salv->info;
		stiva.TOP = penultim;
		delete salv;
		penultim->succ = NULL;
		return elem_sters;
	}
}
int main()
{
	int meniu;
	StackDinamic stiva;

	do
	{
		cout << "0.Iesire din stiva" << endl;
		cout << "1.Initializare stiva" << endl;
		cout << "2.Inserare/PUSH in stiva" << endl;
		cout << "3.Stergere/POP din stiva" << endl;
		cout << "4.PEAK" << endl;
		cout << "5.Traversare stiva,afisare" << endl;
		cout << "Introduceti optiunea[0,5]:";
		cin >> meniu;
		switch (meniu)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			cout << "Initializarea stivei" << endl;
			cout << "Dati info:" << endl;
			int info;
			cin >> info;
			stiva = Reset_StackDinamic(stiva,info);
			break;
		}
		case 2:
		{
			cout << "PUSH stiva:Dati info_nou" << endl;
			int info_nou;
			cin >> info_nou;
			stiva = Push_StackDinamic(stiva, info_nou);
			break;
		}
		case 3:
		{
			cout << "POP stiva:" << endl;
			int element;//are valoare de gunoi de memorie
			int element = Pop_StackDinamic(stiva);
			if (element == NULL)
				cout << "Stiva goala" << endl;
			else
				cout << "S-a scos din stiva " << element << endl;
			break;
		}
		case 4:
		{
			if (EmptyStack(stiva) == false)

				cout << "Varful stivei " << stiva.TOP - 1;
			else
				cout << "Stiva goala nu exista varf" << endl;
			break;
		}
		case 5:
		{
			NodLSI* tmp = stiva.LIST;
			while (tmp != NULL)
			{
				cout << tmp->info << " ";
				tmp = tmp->succ;
			}
		}
		default: cout << "Optiune invalida" << endl;
		}//sf.switch
		cout << "Apasati Enter pentru a sterge ecranul" << endl;
		_getch();
		system("cls");
	} while (meniu != 0);
	return 0;
}

