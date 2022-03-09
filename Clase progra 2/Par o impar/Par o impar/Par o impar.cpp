// Par o impar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int var, h; //Definimos variables
	cout << "Ingresa un numero para decirte si es par o impar" << endl;
	cin >> var; // Ingresamos la variable
	h = var % 2; //Dividimos la variable entre 2

	if (h == 0) { //Si el resultado de la division es 0, es par
		cout << "Par";
	}
	else { //Si no, impar
		cout << "Impar"; 
	}
	getch();
}

