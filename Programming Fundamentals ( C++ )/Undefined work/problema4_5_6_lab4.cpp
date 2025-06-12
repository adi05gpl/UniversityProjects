#include <iostream>												//pdf lab 4
#include <stdio.h>
#include <conio.h>
#include <math.h>		
#include <iomanip>												
using namespace std;

int main()
{/*
	char opt;												//problema 4
	int x, y, z, delta, x1,x2, preal, pimag;

	cout<<("Primul numar este: \n"); cin>>x;
	cout << ("Al doilea numar este: \n"); cin >> y;
	cout << ("Al treilea numar este: \n"); cin >> z;
	printf("a. Afisare maxim: \n");
	printf("b. Afisare minim: \n");
	printf("c .Afisare suma: \n");
	printf("d. Afisare produs: \n");
	printf("e. Afisare Solutie grad 2: \n");

	cout << ("Introduceti optiunea: \n");
	cin >> opt;

	if (opt == 'a')
	{
		if ((x > y) && (x > z))
			cout << x;
		if ((y > x) && (y > z))
			cout << y;
		if ((z > x) && (z > y))
			cout << z;
	}

	if (opt == 'b')
	{
		if ((x < y) && (x < z))
			cout << x;
		if ((y < x) && (y < z))
			cout << y;
		if ((z < x) && (z < y))
			cout << z;
	}

	if (opt=='c')
	{
		cout << x + y + z;
	}

	if (opt == 'd')
	{
		cout << x*y*z;
	}
	if (opt == 'e')
	{
		if (x == 0)
			cout << "Ecuatie de gradul I" << "\n";
		else
			delta = y*y - 4 * x*z;

		if (delta >= 0)
		{

			cout << "Radacini reale: ";
			x1 = (-y + sqrt(delta)) / (2 * x);
			x2 = (-y - sqrt(delta)) / (2 * x);
			cout << "x1 = " << x1 << " x2 = " << x2;

		else
			printf("Solutia contine numere complexe.");
		}

	}
		//scanf_s("%d%d", &x, &y); //&x &y &z, 1);


	_getch();
		return 0;


	int a;														// problema 5
	cout << "a= \n";
	cin >> a;
	cout << "Numar: " << "\n";
	cout << a / 1000 << a % 100;
	_getch();
	return 0;	*/



	float a;
	int a1, a2;													//problema 6
	cout << "a= \n";
	cin >> a;	
	cout << "Primul numar: \n" << (a * 100 - int(a));
	cin >> a1 >> a1 == (a * 100 - int(a));
	cout << "a1= \n";
	cout << "Al doliea numar: \n" << ((a * 100 - int(a)) * 10000 - int(a * 100 - int(a)) * 10000);
	cout << "Al treilea numar: \n" << int((a * 100 - int(a)) * 10000 - int(a * 100 - int(a)) * 10000);


	_getch();
	return 0;
}