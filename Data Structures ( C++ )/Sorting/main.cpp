#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("test.txt",ios::in | ios::binary);
    if(fin == NULL){
        cout << "Fisierul de intrare nu a fost gasit" << endl;
        return -1;
    }
    cout << "Pozitia indicatorului de fisier la deschiderea fisierulu: " << fin.tellg() << endl;
    int nrintreg;
    fin >> nrintreg;
    cout << "Numarul intreg citit: " << nrintreg << endl;
    cout << "Pozitia indicatorului de fisier dupa primul nr intreg citit din fisier: " << fin.tellg() << endl;
    char character;
    fin >> character;
    cout << "Caracterul citit: " << character << endl;
    cout << "Pozitia indicatorului de fisier dupa urmatorul caracter citit din fisier: " << fin.tellg() << endl;
    cout << "Revenire cu o pozitie si citirea aceluiasi caracter inca o data " << endl;
    fin.seekg(-1,ios::cur);
    cout << "Pozitia indicatorului de fisier dupa revenire: " << fin.tellg() << endl;
    fin >> character;
    cout << "Caracterul a fost citit de 2 ori: " << character << endl;
    cout << "Pozitia indicatorului de fisier dupa citirea aceluiasi caracter: " << fin.tellg() << endl;
    fin.close();
    return 0;
}
