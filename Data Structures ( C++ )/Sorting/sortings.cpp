#include<iostream>
using namespace std;

int inserare_vect(int v[], int n){

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
}
int afisare_vect(int v[], int n){

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int sortare_insertie(int v[],int n){

    for(int i = 0; i < n; i++){
       int j = i-1;
       int aux = v[i];
       while(j >= 0 && aux < v[j]){
            v[j+1] = v[j];
            j = j - 1;
       }
       v[j+1] = aux;
    }
}
int shell_sort(int v[], int n, int h[], int nh){

    int pas, temp, i, j, ih;
    for(ih = 0; ih < nh - 1; ih++){
         pas = h[ih];
        for(i = pas; i < n; i++){
             temp = v[i];
            for(j = i; j >= pas && v[j - pas] > temp; j -= pas){
                v[j] = v[j - pas];
            }
            v[j] = temp;
        }
    }
}
int sortare_selectieDirecta(int v[], int n){

    int i, j, aux;
    for(i = 0; i < n - 2; i++){
        for(j = i + 1; j < n - 1; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
int sortare_numarare(int v[], int n){           // NOT WORKING.
    int i, j, contor[n], dest[n];               // MRRRR
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(v[i] > v[j]) contor[i]++;
            else contor[j]++;
        }
    }
    for(i = 0; i < n; i++){
        dest[contor[i]] = v[i];
    }
    for(i = 0; i < n - 1; i++){
        if(dest[i] >= dest[i+1]){
            dest[i+1] = dest[i];
        }
    }
}

int sortare_bubbleV1(int v[], int n){
    int aux, i; bool interschimbare = true;
    do{
        interschimbare = false;
        for(i = 0; i < n - 1; i++){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                interschimbare = true;
            }
        }
    }while(interschimbare == true);
}

int sortare_bubbleV2(int v[], int n){
    int pozitieinterschimbare, pozitie, aux, i;  bool interschimbare = true;
    pozitieinterschimbare = n - 1;
    do{
        interschimbare = false;
        pozitie = 0;
        for(i = 0; i < pozitieinterschimbare; i++){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                interschimbare = true;
                pozitie = i;
            }
        }
        pozitieinterschimbare = pozitie;
    }while(interschimbare == true);
}

int sortare_cocktail(int v[], int n){
    int i, aux;  bool interschimbare = true;
    do{
        interschimbare = false;
        for(i = 0; i < n - 1; i++){     // stanga-dreapta
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                interschimbare = true;
            }
        }
        if(interschimbare == false) break;
        interschimbare = false;
        for(i = n - 1; i < 0; i--){     // dreapta-stanga
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                interschimbare = true;
            }
        }
    }while(interschimbare == true);
}

int maxim(int v[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < v[i])
            max = v[i];
    }
}

int counting_sort(int v[], int n){
    int m, i, fr[n], y[n];
    m = maxim(v, n);
    for(i = 0; i < m; i++) fr[i] = 0;
    for(i = 0; i < n - 1; i++) fr[v[i]]++;
    for(i = 0; i < m; i++) fr[i] = fr[i - 1] + fr[i];
    for(i = n - 1; i < 0; i--){
        y[fr[v[i]] - 1] = v[i];
        fr[v[i]]--;
    }
    for(i = 0; i < n - 1; i++) v[i] = y[i];
}

int main(){
    int v[12], n, nh = 3, h[] = {5, 3, 1};
    cin >> n;
/*  inserare_vect(v, n);      // Insertion
    afisare_vect(v, n);
    sortare_insertie(v, n);
    afisare_vect(v, n);     */

/*  inserare_vect(v, n);      // Shell Sort
    afisare_vect(v, n);
    shell_sort(v, n, h, nh);
    afisare_vect(v, n);     */

/*  inserare_vect(v, n);        // Selection Sort
    afisare_vect(v, n);
    sortare_selectieDirecta(v, n);
    afisare_vect(v, n);     */

/*  inserare_vect(v, n);        // Sortare prin numarare - Broken ?
    afisare_vect(v, n);
    sortare_numarare(v, n);
    afisare_vect(v, n);     */

/*  inserare_vect(v, n);        // Bubble Sort (Varianta 1)
    afisare_vect(v, n);
    sortare_bubbleV1(v, n);
    afisare_vect(v, n);     */

/*  inserare_vect(v, n);        // Bubble Sort (Varianta 2)
    afisare_vect(v, n);
    sortare_bubbleV2(v, n);
    afisare_vect(v, n);     */

/*  inserare_vect(v, n);        // Cocktail Sort (Bubble varianta 3)   --- MIGHT NOT WORK
    afisare_vect(v, n);
    sortare_cocktail(v, n);
    afisare_vect(v, n);     */

    inserare_vect(v, n);
    afisare_vect(v, n);
    counting_sort(v, n);
    afisare_vect(v, n);
}
