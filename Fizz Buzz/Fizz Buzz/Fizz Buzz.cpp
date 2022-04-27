// Fizz Buzz.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//



#include <iostream>
#include <conio.h>
using namespace std;

void burbuja();

//constexpr int COUNT = 100;
/*
int main() {

    for (int i = 1; i <= COUNT; ++i) { // No utilicé muchos {} para los if else

        if (i % 15 == 0) //Jerarquicé que el programa siempre busque primero si es divisible entre 15 porque se queda con el primer resultado.
            cout << "FizzBuzz, ";
        else if (i % 5 == 0)
            cout << "Buzz, ";
        else if (i % 3 == 0)
            cout << "Fizz, ";
        else
            cout << i << ", ";

    }

    return 0;
}
*/

// Clase personalizada para resolver este mismo ejercicio.
/*
#include <iostream>
#include <string>
#include <map>

using std::cout; using std::endl;
using std::string; using std::cin;
using std::map;

constexpr int COUNT = 100;

class FizzBuzz {
    map<int, string> table;
public:
    explicit FizzBuzz(map<int, string>& init) :
        table(std::move(init)) {}

    void checkFizzBuzz() {
        for (int i = 1; i <= COUNT; ++i) {
            for (const auto& item : table) {
                i% item.first == 0 ?
                    cout << item.second << ", " :
                    cout << i << ", ";
                break;
            }
        }
    }
};

int main() {
    map<int, string> init = { {3, "Fizz"},
                            {5, "Buzz"},
                            {15, "FizzBuzz"} };

    FizzBuzz fii(init);
    fii.checkFizzBuzz();

    return EXIT_SUCCESS;
}
*/

/*
#include <iostream>
#include <string>
#include <map>
#include <initializer_list>

using std::cout; using std::endl;
using std::string; using std::cin;
using std::map;

constexpr int COUNT = 100;

class FizzBuzz {
    map<int, string> table;
public:
    FizzBuzz(std::initializer_list<std::pair<int, string>> init) {
        for (const auto& item : init) {
            table.insert(item);
        }
    }

    void checkFizzBuzz() {
        for (int i = 1; i <= COUNT; ++i) {
            for (const auto& item : table) {
                i% item.first == 0 ?
                    cout << item.second << ", " :
                    cout << i << ", ";
                break;
            }
        }
    }
};

int main() {
    FizzBuzz fii = { {3, "Fizz"},
                    {5, "Buzz"},
                    {15, "FizzBuzz"} };

    fii.checkFizzBuzz();

    return EXIT_SUCCESS;
}
*/

//Busqueda binaria con metodo burbuja como método de ordenamiento.

int main() {
    int numeros = Burbuja();
    int sup, inf, mitad, dato;
    char band = 'F';
    
    Burbuja();
    dato = 4;
    //Algoritmo de la busqueda binaria
    inf = 0;
    sup = 5;

    while (inf <= sup) {
        mitad = (inf + sup) / 2;

        if (numeros[mitad] == dato) {
            band = 'V';
            break;
        }
        if (numeros[mitad] > dato) {
            sup = mitad;
            mitad = (inf + sup) / 2;
        }
        if (numeros[mitad] < dato) {
            inf = mitad;
            mitad = (inf + sup) / 2;
        }
    }

    if (band == 'V') {
        cout << "El numero ha sido encontrado en la posicion: " << mitad << endl;
    }
    else {
        cout << "El numero NO ha sido encontrado ";
    }

    return 0;
}

void Burbuja() {
    int numeros[] = { 4,3,2,5,1 };
    int i, j, aux;

    for (i = 0, i < 5, i++) {
        for (j = 0, j < 5, j++) {
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

    cout << "Orden ascendente: ";
    for (i = 0; i < 5; i++) {
        cout << numeros[i] << "";
    }
}