// Insertion y Heap sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<iostream>
#include<conio.h>

using namespace std;

// A function to implement bubble sort
void bubbleSort(int numeros[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++) {

			if (numeros[j] > numeros[j + 1]) {
				swap(numeros[j], numeros[j + 1]);
			}
		}
	}
}

/* Function to print an array */
void printArray(int numeros[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << numeros[i] << " ";
	cout << endl;
}

int main() {

	int numeros[10], n, opc, numero;

	cout << "Digite el numero de elementos: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Digite un numero: ";
		cin >> numeros[i]; //Guardamos los numeros en el arreglo
	}

	cout << "\tMENU" << endl;
	cout << "1. Bubble sort" << endl;
	cout << "2. Insertion sort" << endl;
	cout << "3. Quicksort" << endl;
	cout << "4. Merge sort" << endl;
	cout << "5. Heap sort" << endl;
	cout << "6. Binary search" << endl;
	cout << "Opcion: ";
	cin >> opc;

	switch (opc) {
	case 1:

		

		// Driver code
		int n = sizeof(numeros) / sizeof(numeros[0]);
		bubbleSort(numeros, n);
		cout << "Sorted array: \n";
		printArray(numeros, n);
		break;
	}
}



