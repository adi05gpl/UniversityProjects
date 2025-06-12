#include<iostream>
#include<math.h>
using namespace std;

int n, *v, k;

void init(){
    v[k] = 0;
}
bool am_succesor(){
	if(v[k] < n){
		v[k]++;
		return true;
	}
	else return false;
}
bool e_valid(){
    return true;
}
bool solutie(){
	if(k == n - 1)
		return true;
	else
		return false;
}
int tipar(){
    for(int i = 0; i <= k; i++) cout << v[i] << " ";
    cout << endl;
}
void back(){
    k = 0;
    init();
    bool AS;
    while(k >= 0){
        do{}
        while((AS = am_succesor()) && !e_valid());
        if(AS){
            if(solutie()) tipar();
            else {k++; init();}
        }else k--;
    }
}
int main(){
    cout << "Dati n: ";
    cin>>n;
	v = new int[n];
	cout << "Produsele carteziene sunt: \n";
	back();
	delete[] v;
	return 0;
}
