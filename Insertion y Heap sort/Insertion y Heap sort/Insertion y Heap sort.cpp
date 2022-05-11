// Insertion y Heap sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>

using namespace std;

struct Libros {
	char titulo[50];
	int isbn;
	char autor[30];
}libros[6];


int main() {
	int n_libros, i, j, aux, opc;
	cout << "Digite el numero de libros que quiera crear: "; cin >> n_libros;
	cin.ignore();
	for (i = 0; i < n_libros; i++) {
		cout << "\nIngrese el titulo del libro: "; cin.getline(libros[i].titulo, 50, '\n');
		cout << "Ingrese el ISBN: "; cin >> libros[i].isbn;
		cin.ignore();
		cout << "Ingrese el autor del libro: "; cin.getline(libros[i].autor, 30, '\n');
		cout << "Libro ingresado.\n\n";
	}

	cout << "\nAhora decide como quieres acomodarlos:" << endl;
	cout << "1. Bubble sort" << endl;
	cout << "2. Insertion sort" << endl;
	cout << "3. Quicksort" << endl;
	cout << "4. Merge sort" << endl;
	cout << "5. Heap sort" << endl;
	cout << "6. Binary search" << endl;
	cout << "Opcion: ";
	cin >> opc;
	cin.ignore();

	switch (opc) {
	case 1: cout << "\nOrdenando por metodo burbuja\n" << endl;
		int i, j, aux;

		for (i = 0; i < n_libros; i++) {
			for (j = 0; j < n_libros - 1; j++) { //cantidad de elementos -1
				if (libros[j].isbn > libros[j + 1].isbn) { //Si el valor de esta posicion es mayor a la siguiente posicion hacer el cambio
					aux = libros[j].isbn;
					libros[j].isbn = libros[j + 1].isbn;
					libros[j + 1].isbn = aux;
				}
			}
		}
		for (i = 0; i < n_libros; i++) {
			cout << "ISBN: " << libros[i].isbn<<"\nAutor: " << libros[i].autor << "\nTitulo:" << libros[i].titulo << "\n" << endl;
		}
		break;
	case 2: cout << "Ordenando por metodo insertion";
		int piv;

		for (i = 0; i < n_libros; i++) {
			//Los valores se guardan antes para poder hacer el cambio sin borrar datos
			piv = i; //La iteracion es igual al pivote
			aux = libros[i].isbn; //aux es igual al valor que se este iterando
			while ((piv > 0) && (libros[piv - 1].isbn > aux)) {//Mientras que la posicion del pivote sea mayor que 0(o sea, nada a su izquierda) y el valor de la izquierda sea menor que el valor que se esta iterando 
				libros[piv].isbn = libros[piv - 1].isbn; //El valor de la izquierda adopta el valor que se esta iterando
				piv--; //Pivote sigue buscando un lugar donde no se cumpla esta condicion
			}
			libros[piv].isbn = aux; //Si no es la primer posicion y el valor de la izquierda no es mayor que el valor iterado, el valor iterado es ahora aux
		}
		for (i = 0; i < n_libros; i++) {
			cout << "ISBN: " << libros[i].isbn << "\nAutor: " << libros[i].autor << "\nTitulo:" << libros[i].titulo << "\n" << endl;
		}
		break;
	case 3: cout << "Ordenando por metodo Quick";

		break;
	case 4: cout << "Ordenando por merge";

		break;
	case 5: cout << "Ordenando por heap";

		break;
	case 6: cout << "Busqueda binaria\n";
		int inf, sup, mitad, dato;
		char band = 'F';

		cout << "\nIngrese el ISBN a buscar: "; cin >> dato;
		inf = 0;//	Donde comienza
		sup = n_libros;//Numero de elementos del arreglo
		while (inf <= sup) {
			mitad = (inf + sup) / 2;

			if (libros[mitad].isbn == dato) {
				band = 'V';
				break;
			}
			if (libros[mitad].isbn > dato) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (libros[mitad].isbn < dato) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (band == 'V') {
			cout << "El numero ha sido encontrado en la posicion " << mitad;
			for (i = 0; i < n_libros; i++) {
				cout << "\nISBN: " << libros[i].isbn << "\nAutor: " << libros[i].autor << "\nTitulo:" << libros[i].titulo << "\n" << endl;
			}
		}
		else {
			cout << "El numero no ha sido encontrado.";
		}
		break;
	}
}
