// QuickSort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernández

#include <iostream>
using namespace std;

// Funcion para cambiar posiciones
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta funcion toma como pivote al ultimo elemento, lo coloca en su posicion correcta dentro del arreglo
pone a sus menores a la izquierda y sus mayores a la derecha del pivote*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivote
	int i = (low - 1); // indice del elemento mas pequeño del arreglo e indica la posicion correcta del pivote hasta ahora

	for (int j = low; j <= high - 1; j++)
	{
		// Si el elemento actual es menor al pivote
		if (arr[j] < pivot)
		{
			i++; // incrementar el indice de los elementos más pequeños
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* Funcion principal
arr[] --> Arreglo a ordenar,
low --> índice inicial,
high --> Índice final */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi es el índice particionando, arr[p] está ordendado */
		int pi = partition(arr, low, high);

		// De manera separada, ordena los elementos antes y después de la particion
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
/* Funcion para imprimir */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Main
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 }; //Arreglo
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Arreglo ordenado: \n";
	printArray(arr, n);
	return 0;
}
