// Busqueda binaria.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// Si el elemento se encuentra en el medio, retorna mid.
		if (arr[mid] == x)
			return mid;

		// Si el elemento es menor que mid, entonces solo puede estar en el subarray de la izquierda
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// En caso contrario, el elemento solo puede estar en el subarray de la derecha
		return binarySearch(arr, mid + 1, r, x);
	}

	// Si elemento no esta en el array
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "El elemento no se encuentra en el array."
		: cout << "El elemento se encuentra en el indice: " << result;
	return 0;
}