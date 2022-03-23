// Listas progra 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

//Prototipos de funciones
void menu();
void insertLista(Nodo*&, int);
void mostrarLista(Nodo*);
void buscarLista(Nodo*, int);
void eliminarNodo(Nodo*&, int);

Nodo* lista = NULL;
int main()
{

	menu();


	getchar();

	return 0;
}

void menu() {
	int opcion, dato;
	do {
		cout << "\t.:MENU:.\n";
		cout << "1. Insertar elementos a la lista\n";
		cout << "2. MOstrar elementos de la lista\n";
		cout << "3. Buscar un elemento en la lista\n";
		cout << "4. Eliminar un nodo de la lista\n";
		cout << "5. Salir\n";
		cin >> opcion; 

		switch (opcion) {
		case 1: cout << "Inserte un numero: " << endl;
			cin >> dato;
			insertLista(lista, dato);
			cout << "\n";
			system("pause");
			break;

		case 2: mostrarLista(lista);
			cout << "\n";
			system("pause");
			break;
		case 3: cout << "\nDigite un numero a buscar: ";
			cin >> dato;
			buscarLista(lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 4: cout << "\nDigite el elemento que desea eliminar: ";
			cin >> dato;
			eliminarNodo(lista, dato);
			cout << "\n";
			system("pause");
			break;
		}
		
		system("cls");
	} while (opcion != 5);
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

void mostrarLista(Nodo* Lista) {
	Nodo* actual = new Nodo();
	actual = Lista;

	while (actual != NULL) {
		cout << actual->dato << " -> ";
		actual = actual->siguiente;
	}
}

void buscarLista(Nodo* lista, int n) {
	bool band = false;
	Nodo* actual = new Nodo();
	actual = lista;
	while ((actual != NULL) && (actual->dato <= n)) {

		if (actual->dato == n) {
		band = true;
		}
		actual = actual->siguiente;
	}

	if (band == true) {
		cout << "Elemento " << n << "Si a sido encontrado en lista\n";
	}
	else {
		cout << "Elemento " << n << "No ha sido encontrado en lista\n";
	}
}

void eliminarNodo(Nodo*& lista, int n) {
	//Preguntar si la lista esta vacia
	if (lista != NULL) {
		Nodo* aux_borrar;
		Nodo* anterior = NULL;
		aux_borrar = lista;
		//Recorrer la lista
		while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//El elemento no ha sido encontrado
		if (aux_borrar == NULL) {
			cout << "El elemento no ha sido encontrado";
		}
		//El primer elemento que vamos a eliminar
		else if (anterior == NULL) {
			lista == lista->siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero no es el primer nodo
		else {
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}