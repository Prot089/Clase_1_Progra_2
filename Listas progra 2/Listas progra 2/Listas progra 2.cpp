// Listas progra 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

//Prototipos de funciones
void insertLista(Nodo*&, int);

int main()
{
	Nodo* lista = NULL;

	int dato;

	cout << "Inserte un numero: " << endl;
	cin >> dato;
	insertLista(lista, dato);

	cout << "Inserte un numero: " << endl;
	cin >> dato;
	insertLista(lista, dato);

	cout << "Inserte un numero: " << endl;
	cin >> dato;
	insertLista(lista, dato);

	cout << "Inserte un numero: " << endl;
	cin >> dato;
	insertLista(lista, dato);

	cout << "Inserte un numero: " << endl;
	cin >> dato;
	insertLista(lista, dato);


	getchar();

	return 0;
}

void insertLista(Nodo *&lista, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;

	Nodo* aux = lista;
	Nodo* aux2 = 0;

	while ((aux != NULL) && (aux->dato < n)) {
		aux2 = aux;
		aux = aux->siguiente;
	}
	if (lista == aux) {
		lista = nuevo_nodo;
	}
	else {
		aux2->siguiente = nuevo_nodo;
	}

	nuevo_nodo->siguiente = aux;

	cout << "Elemento " << n << " insertado correctamente\n";
}
