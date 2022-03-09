// Factorial.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int arg, char** argv) //El main principal que alberga 2 tipos de dato y uno es un doble puntero
{
	int num, fact=1; //Definimos tipos de dato

	cout << "Cual numero voy a factorizar?" << endl;
	cin >> num; //Ingresar el tipo de dato

	for (int i=num; i > 0; i--) { // Un ciclo inverso para sacar el factorial de un numero
		fact = fact * i; //Fact es igual a fact por las veces de interacciones
	}
	cout << fact;
	return 0;
}

