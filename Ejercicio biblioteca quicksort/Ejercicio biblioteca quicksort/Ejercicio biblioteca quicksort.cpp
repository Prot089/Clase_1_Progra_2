// Ejercicio biblioteca quicksort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

struct libro {
    int isbn;
    string nombre;
    int n_pag;
    string autor;
};

int numeroLibros = 0;
string textoTemporal;
int numeroTemporal;

int main()
{
    libro* libros = new libro[6];
    cout << "Introduce el nombre del Libro: ";
    cin >> libros[numeroLibros].nombre;
    cout << "Introduce su ISBN: ";
    cin >> libros[numeroLibros].isbn;
    numeroLibros++;  // Y tenemos un libro más

    cout << "Nombre: " << libros[numeroLibros].nombre << endl;
    cout << "ISBN: " << libros[numeroLibros].isbn << endl;
}


