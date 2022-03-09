// Fibonacci.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
        int suma = 1; //Definimos los tipos de dato
        int aux = 0; 
        int a = 0;
        int limite = 0; 
        bool resultado = false; 

        cout << "Dentro de la secuencia de Fibonacci, cual numero estas buscando?\n";
        cin >> limite; //Definimos cual es el numero que estamos buscando, en cual se va a detener

        while (resultado == false) //Ciclo mientras no haya llegado al limite, puede continuar
        {
            cout << suma << endl;
            if (suma >= limite) {
                resultado = true;
                cout << "Ahi termina la secuencia hasta encontrar tu numero\n";
                if (suma == limite) {
                }
                else {
                    cout << "Nel pa, ese no esta dentro de la serie de Fibonacci\n"; // El numero ingresado no se encuentra en la serie de fibonacci
                }
            }
            a = suma;
            suma = suma + aux;
            aux = a;
        }
        return 0;
}

