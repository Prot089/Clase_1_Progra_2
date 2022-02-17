// Area de Rombo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void)
{
    float area, diagonal_mayor, diagonal_menor;
    cout << "Ingresa el valor de diagonal mayor: ";
    cin >> diagonal_mayor;
    cin.get();
    cout << "Ingresa el valor de diagonal menor: ";
    cin >> diagonal_menor;
    cin.get();
    area = diagonal_mayor * diagonal_menor / 2;
    cout << "Valor de area: " << area << endl;
    cout << endl;
    system("pause");
    return 0;
}