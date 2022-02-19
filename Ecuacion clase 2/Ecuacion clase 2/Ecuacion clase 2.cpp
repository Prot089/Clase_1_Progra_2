// Ecuacion clase 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernández

//Incluimos las bibliotecas necesarias para el funcionamiento de nuestro codigo 
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
	double n, m, div, raiz, res, r; // Aqui declaramos las variables que vamos a utilizar:)
	int multi; //El operador para multiplicacion no se puede realizar si no es enteros

	cout << "Realizaremos la operacion 2\n"; //Mensaje arrojado
	cout << "Ingresa un numero para el valor de n: "; // Mensaje arrojado 
	cin >> n; // Obtencion del valor de la variable "n"
	cout << "Ingresa un numero para el valor de m: "; // Mensaje arrojado
	cin >> m; // Aqui obtenemos la variable "m"

	// Esta parte del codigo es para hacer los calculos 
	div = n / 2; // Se divide la variable n entre 2
	raiz = sqrt(div); // Se saca la raiz cuadrada al resultado de la division 
	multi = raiz * m; //Se multiplica por m el resultado anterior
	res = multi % 3; //Se saca el residuo del resultado de la mutiplicacion entre 3 

	cout << "Este es el resultado: " << res; //Aqui se muestra el resultado final
	return 0;
}
