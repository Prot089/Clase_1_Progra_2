// Factorial.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int arg, char** argv)
{
	int num, fact=1;

	cout << "Cual numero voy a factorizar?" << endl;
	cin >> num;

	for (int i=num; i > 0; i--) {
		fact = fact * i;
	}
	cout << fact;
	return 0;
}

