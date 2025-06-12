#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
struct NodABC{
	int info;
	NodABC* fiu_stang;
	NodABC* fiu_drept;
};
NodABC* initializare_ABC(NodABC* root)
{
	root = NULL;
	return root;
}
NodABC* inserare_ABC(NodABC* root,int info_nou)
{
	if (root == NULL)
	{
		root = new NodABC;
		root->info = info_nou;
		root->fiu_stang = NULL;
		root->fiu_drept = NULL;
	}
	else
	{
		NodABC* tmp = root;
		NodABC* tata = NULL;
		while (tmp != NULL)
		{
			tata = tmp;
			if (info_nou < tmp->info)
			{
				tmp = tmp->fiu_stang;
			}
			else
			{
				if (info_nou > tmp->info)
					tmp = tmp->fiu_drept;
				else
				{
					cout << "Info este deja in ABC deci nu se poate insera" << endl;
					return root;
				}
			}
		  }

		NodABC* nou = new NodABC;
		nou->info = info_nou;
		nou->fiu_stang = NULL;
		nou->fiu_drept = NULL;
		if (tata->info < nou->info)
		
			tata->fiu_drept = nou;
		else
			tata->fiu_stang = nou;
	}
	
	return root;
}
void preordine(NodABC* root)
{
	if (root!=NULL)
	{
		cout << root->info << " ";
		preordine(root->fiu_stang);
		                    
		preordine(root->fiu_drept);
	}
}
void inordine(NodABC* root)
{
	if (root != NULL)
	{
		inordine(root->fiu_stang);
		cout << root->info << " ";
		inordine(root->fiu_drept);
	}
}
void postordine(NodABC* root)
{
	if (root != NULL)
	{
		postordine(root->fiu_stang);
		postordine(root->fiu_drept);
		cout << root->info << " ";
	}
}
NodABC* caz1(NodABC* root, NodABC* tmp, NodABC* tata)
{
	
	if (tmp == root)
	{
		delete root;
		root = NULL;
	}
	else
	{
		if (tata->fiu_stang == tmp)
		{
			tata->fiu_stang = NULL;
			delete tmp;
		}
		else
		{
			tata->fiu_drept = NULL;
			delete tmp;
		}
	}
	return root;
}
NodABC* caz2(NodABC* root, NodABC* tmp, NodABC* tata)
{
	if (tata->fiu_stang == tmp&&tmp->fiu_stang != NULL)
	{
		tata->fiu_stang = tmp->fiu_stang;
		delete tmp;
	}
	if (tata->fiu_stang == tmp&&tmp->fiu_drept != NULL)
	{
		tata->fiu_stang = tmp->fiu_drept;
		delete tmp;
	}
	if (tata->fiu_drept == tmp&&tmp->fiu_drept != NULL)
	{
		tata->fiu_drept = tmp->fiu_drept;
		delete tmp;
	}
	if (tata->fiu_drept == tmp&&tmp->fiu_stang != NULL)
	{
		tata->fiu_drept = tmp->fiu_stang;
		delete tmp;
	}
	if (root == tmp)
	{
		if (tmp->fiu_stang != NULL)
			root = tmp->fiu_stang;
		else
		{
			root = tmp->fiu_drept;
			delete tmp;
		}
	}
	return root;
}
NodABC* caz3(NodABC* root, NodABC* tmp, NodABC* tata)
{
    
	NodABC* max=tmp->fiu_stang;
	NodABC* tata_max=tmp;
	while(max->fiu_drept!=NULL)
	{
	    tata_max=max;
		max=max->fiu_drept;
	}
	tmp->info=max->info;
	root=caz2(root,max,tata_max);
	if(tata_max->fiu_stang==max)
	{
	    if(max->fiu_stang!=NULL)
		    tata_max->fiu_stang=max->fiu_stang;
	    else  tata_max->fiu_stang=max->fiu_drept;
	}
	else
	{
	    if(max->fiu_stang!=NULL)
		{
		    tata_max->fiu_drept=max->fiu_stang;
		}
		else tata_max->fiu_drept=max->fiu_drept;
	}
		    
		
	delete max;
	return root;
		
}
NodABC* stergere_ABC(NodABC* root, int info_sters)
{
	if (root == NULL)
	    cout << "ABC vid";
	else
	{
		NodABC* tmp = root;
		NodABC* tata = NULL;
		while (tmp != NULL&&tmp->info != info_sters)
		{
			
			tata = tmp;
			if (info_sters < tmp->info)
			{
				tmp = tmp->fiu_stang;
			}
			if (info_sters > tmp->info)
				tmp = tmp->fiu_drept;
		}
		if (tmp == NULL)
		{
			cout << "Info_sters nu e in arbore";
			return root;
		}
		
		if (tmp->fiu_stang == NULL&&tmp->fiu_drept == NULL)
		{
			root = caz1(root, tmp, tata);
		}
		else
		{
			if ((tmp->fiu_stang != NULL&& tmp->fiu_drept == NULL) || (tmp->fiu_stang == NULL&&tmp->fiu_drept != NULL))
			{
				root = caz2(root, tmp, tata);
			}
			else
				
			{
				root=caz3(root,tmp,tata);
			}
		}
	}
	return root;
	
}
void eliberare_ABC(NodABC* tmp)
{
	if (tmp != NULL)
	{
		eliberare_ABC(tmp->fiu_stang);
		eliberare_ABC(tmp->fiu_drept);
		delete tmp;
	}
}
NodABC* cautare_ABC(NodABC* root, int cheia_caut)
{
	NodABC* tmp = root;
	while (tmp != NULL)
	{
		if (cheia_caut < tmp->info)
			tmp = tmp->fiu_stang;
		else
		{
			if (cheia_caut > tmp->info)
				tmp = tmp->fiu_drept;
			else
				return tmp;
		}
	}
	return tmp;
}
NodABC* actualizare_ABC(NodABC* root, int cheia_caut, int info_nou)
{
	NodABC* adr = cautare_ABC(root, cheia_caut);
	if (adr == NULL)
		cout << "EROARE,NODUL NU A PUTUT FII GASIT";
	else
		adr->info = info_nou;
	return root;
}
int adancimeMaxima_ABC(NodABC* root)
{
	int adancimeS = 0;
	int adancimeD = 0;
	if (root = NULL)
		return 0;
	else
	{
		 adancimeS += adancimeMaxima_ABC(root->fiu_stang);
		 adancimeD += adancimeMaxima_ABC(root->fiu_drept);
		if (adancimeS > adancimeD)
			return adancimeS + 1;
		else
			return adancimeD + 1;
	}
}
int nivelDat_ABC(NodABC* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 0)
	{
		cout << root->info;
		return 0;
	}
	else
	{
		nivelDat_ABC(root->fiu_stang, k - 1);
		nivelDat_ABC(root->fiu_drept, k - 1);
	}
}
int structura_ABC(NodABC* root, NodABC* root2)
{
	if (root == NULL&&root2 == NULL)
		return 1;
	if (root != NULL&&root2 != NULL)
	{
		return(root->info == root2->info&&structura_ABC(root->fiu_stang, root2->fiu_stang) && structura_ABC(root->fiu_drept, root2->fiu_drept));

	}
	return 0;
}

/*NodABC* stergereFrunza_ABC(NodABC* root)
{
	if (root->fiu_stang == NULL&&root->fiu_drept == NULL)
	{
		delete(root);
		return NULL;
	}
	root->fiu_stang = stergereFrunza_ABC(root->fiu_stang);
	root->fiu_drept = stergereFrunza_ABC(root->fiu_drept);
	return root;
}*/

NodABC* stergereNivelDat_ABC(NodABC* root, int k)
{
	if (root->fiu_drept)
	{
		if (k == 0)
		{
			stergere_ABC(root,root->fiu_drept->info);
			root->fiu_drept = NULL;
		}
		else
			stergereNivelDat_ABC(root->fiu_drept, k - 1);
	}
	if (root->fiu_stang)
	{
		if (k == 0)
		{
			stergere_ABC(root,root->fiu_stang->info);
			root->fiu_stang = NULL;
		}
		else
			stergereNivelDat_ABC(root->fiu_stang, k - 1);
	}
	return root;
}
int main()
{
	int meniu;
	NodABC* root = NULL;
	do {
		cout << "0.Iesire din program" << endl;
		cout << "1.Initializare arbore" << endl;
		cout << "2.Inserare arbore" << endl;
		cout << "3.Cautare" << endl;
		cout << "4.Stergere" << endl;
		cout << "5.Traversare preordine" << endl;
		cout << "6.Traversare inordine" << endl;
		cout << "7.Traversare postordine" << endl;
		cout << "8.Eliberare" << endl;
		cout << "9.Determinarea adancimii maxime a arborelui" << endl;
		cout << "10.Determinarea tuturor nodurilor aflate pe un nivel dat" << endl;
		cout << "11.Verificare egalitate structurala intre doi arbori" << endl;
		cout << "12.Stergerea frunzelor curente" << endl;
		cout << "13.Stergerea nodurilor de la un nivel dat" << endl;
		cout << "Introduceti optiune [0-13]:";
		cin >> meniu;
		switch (meniu)
		{
		case 0:
			break;
		case 1:
		{
			root = initializare_ABC(root);
			break;
		}
		case 2:
		{
			cout << "Dati info_nou:";
			int info;
			cin >> info;
			root = inserare_ABC(root, info);
			break;
		}
		case 3:
		{
			cout << "Introduceti cheia_caut:" << endl;
			int cheia_caut;
			cin >> cheia_caut;
			NodABC* adr = cautare_ABC(root, cheia_caut);
			if (adr == NULL)
				cout << "EROARE,NODUL NU A PUTUT FII GASIT" << endl;
			else
				cout << "Nodul a fost gasit cu succes" << endl;
			break;
		}
		case 4:
		{
			cout << "Introduceti nodul de sters:" << endl;
			int info_sters;
			cin >> info_sters;
			root = stergere_ABC(root, info_sters);
			break;
		}
		case 5:
		{
		    
			preordine(root);
			break;
		}
		case 6:
		{
			inordine(root);
			break;
		}
		case 7:
		{
			postordine(root);
			break;
		}
		case 8:
		{
		    eliberare_ABC(root);
			break;
		}
		case 9:
		{
			cout << "Adancimea arborelui este egala cu:" << adancimeMaxima_ABC(root);
			break;
		}
		case 10:
		{
			cout << "Introduceti nivelul:";
			int k;
			cin >> k;
			nivelDat_ABC(root, k);
			break;
		}
		case 11:
		{
			NodABC* root2 = NULL;
			root2 = initializare_ABC(root2);
			cout << "Se vor introduce numere pana la aparitia caracterului 'a'" << endl;
			int info2;
			cout << "Introduceti:" << endl;
			cin >> info2;
			while (info2 != 'a')
			{
				root2 = inserare_ABC(root2, info2);
				cout << "Introduceti:" << endl;
				cin >> info2;
			}
			if (structura_ABC(root, root2))
				cout << "Arborii sunt egali" << endl;
			else
				cout << "Arborii nu sunt egali" << endl;
			break;
		}
		case 12:
		{
			root = stergereFrunza_ABC(root);
			break;
		}
		case 13:
		{
			cout << "Introduceti nivelul:" << endl;
			int k;
			cin >> k;
			root = stergereNivelDat_ABC(root, k);
		}
		default:
		{
			cout << "Optiune invalida";
			break;
		}
		}
		cout << "Apasati o tasta pentru a sterge ecranul" << endl;
		_getch();
		system("cls");
	} while (meniu != 0);
}

//adancimea unui arbore:apelare recursiva:1+max(adancime(stang)adancime(drept))..........if adancime de 0 apel trivial