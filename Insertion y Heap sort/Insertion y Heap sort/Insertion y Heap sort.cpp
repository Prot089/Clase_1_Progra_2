// Insertion y Heap sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include<iostream>
#include<conio.h>

using namespace std;

int opc;
// A function to implement bubble sort
void bubbleSort(int array[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++) {

			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

/* Function to print an array */
void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

/* Function to sort an array using insertion sort*/
void insertionSort(int array[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = array[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArrayInsertion(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {

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
		int array[10];

		for (int i = 0; i < 10; i++) {
			cout << "Digite un numero: ";
			cin >> array[i]; //Guardamos los numeros en el arreglo
		}

		int n = sizeof(array) / sizeof(array[0]);
		bubbleSort(array, n);
		cout << "Sorted array: \n";
		printArray(array, n);
		break;
	case 2:
		int array[10];

		for (int i = 0; i < 10; i++) {
			cout << "Digite un numero: ";
			cin >> array[i]; //Guardamos los numeros en el arreglo
		}

		/* Driver code */
		int n = sizeof(array) / sizeof(array[0]);
		insertionSort(array, n);
		printArrayInsertion(array, n);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}

}
