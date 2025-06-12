#include<iostream>

#define SIZE 10

using namespace std;

void bucketSort(int a[], int n) {
    int i, j, k, buckets[SIZE];

    for(i = 0; i < SIZE; ++i)
        buckets[i] = 0;

    for(i = 0; i < n; ++i)
        ++buckets[a[i]];

    for(i = 0, j = 0; j < SIZE; ++j)
        for(k = buckets[j]; k > 0; --k)
            a[i++] = j;
}
void bucketSorts(int v[10], int n){
    int i, j, k, buckets[20];
    for(i = 0; i < 20; i++){
        buckets[i] = 0;
    }
    for(i = 0; i < n; i++){
        ++buckets[v[i]];
    }
    for(i = 0, j = 0; j < 20; j++){
        for(k = buckets[j]; k > 0; k--){
            v[i++] = j;
        }
    }
}
int main() {
    int i, a[] = {3, 6, 5, 1, 8, 4, 3, 1}, v[10], n;
    cout << "Introduceti un numar intre 0-9 !";
    cin >> n;
    cout << "Dati valoarea celor " << n << " elemente!! : " << endl;
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Cele 10 elemente sunt: " << endl;
    for(i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    bucketSorts(v,n);
    cout << "Elementele au fost aranjate !\nPriviti: " << endl;
    for(i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << "Before sorting:\n";
    for(i = 0; i < n; ++i)
        cout << a[i] << " ";

    bucketSort(a, n);

    cout<< "\n\nAfter sorting:\n";
    for(i = 0; i < n; ++i)
        cout<< a[i] << " ";

    return 0;
}
