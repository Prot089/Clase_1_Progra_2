// Par o impar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int var, h;
	cout << "Ingresa un numero para decirte si es par o impar" << endl;
	cin >> var;
	h = var % 2;

	if (h == 0) {
		cout << "Par";
	}
	else {
		cout << "Impar";
	}
	getch();
}

