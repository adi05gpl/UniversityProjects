#include<iostream>
using namespace std;

int citire(int v[], int n){
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
}
int afisare(int v[], int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int maxim(int inceput, int sfarsit, int v[]){
    if(inceput >= sfarsit) return v[inceput];
    else{
      int mijloc = (inceput + sfarsit) / 2;
       int max1 = maxim(inceput, mijloc, v);
       int max2 = maxim(mijloc + 1, sfarsit, v);
        if(max1 > max2) return max1;
        else return max2;
    }
}
int cautare_binara(int inceput, int sfarsit, int v[], int elementCaut){
    if(inceput > sfarsit) return -1;
    else{
       int mijloc = (inceput + sfarsit) / 2;
        if(v[mijloc] == elementCaut) return mijloc;
        else{
            cautare_binara(inceput, mijloc, v, elementCaut);
            cautare_binara(mijloc + 1, sfarsit, v, elementCaut);
        }
        if( !elementCaut ) cout << "Nu se afla in vector !" << endl;
    }
}
int interclasare(int inc, int mijl, int sf, int v[]){
    int i = inc, j = mijl + 1, k = 0, temp[8];
    while(i <= mijl && j <= sf){
        if(v[i] < v[j]){
            temp[k] = v[i];
            k += 1;
            i += 1;
        }else{
            temp[k] = v[j];
            j += 1;
            k += 1;
        }
    }
    while(i <= mijl){
        temp[k] = v[i]; k++; i++;
    }
    while(j <= sf){
        temp[k] = v[j]; k++; j++;
    }
    for(i = inc; i < sf; i++){
        v[i] = temp[i - inc];
    }
}
int merge_sort(int inc, int sf, int v[]){
    if(inc > sf) return 0;
    else{
        int mijl = (inc + sf) / 2;
        merge_sort(inc, mijl, v);
        merge_sort(mijl + 1, sf, v);
        interclasare(inc, mijl, sf, v);
    }
}
int quickSort(int inc, int sf, int v[]){
    if(inc < sf){
        pozpivot = pozitionare(inc, sf, v[]);
        quickSort(inc, pozpivot - 1);
        quickSort(pozpivot + 1, sf);
    }
}
int pozitionare(int inc, int sf, int v[]){
    P = v[inc];
    pozP = inc;
    for(i = inc + 1; i < sf; i++){
        if(v[i] < P){
            pozP++;
            interschimba(v[i], v[pozP]);
        }
    }
    interschimba(v[inc], v[pozP]);
    return pozP;
}
int main(){
    int n, v[8], k;
    cin >> n;

    citire(v, n);
    afisare(v, n);
    cout << "Maximul vectorului: " << maxim(0, n - 1, v) << endl;
    cout << "Introduceti numarul pe care doriti sa il cautati din vector: " << endl;
    cin >> k;
    cout << "Cautare binara: " << cautare_binara(0, n-1, v, k);
    merge_sort(0, n-1, v);
    afisare(v, n);
}
