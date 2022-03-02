// Herencias2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernández

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;
/*
class Enemigo { //Aqui se hace la clase padre
public: //Definimos si es publica, privada o protegida
	string covenant = "Sanghelios"; //Establecemos la variante de covenant como Sanghelios
	void Honck() { //Esta es una funcion para poner texto antes de la informacion de nuestra variable llamada
		cout << "Alerta: ";
	}
};

class rango : public Enemigo { //La clase rango es hijo de la case Enemigo
public: //La clase es publica
	string raza = "Coronel"; //Definimos otra variable y su valor
};

int main() { //La funcion main que el programa llevara a cabo
	rango hostil; //Aqui llamamos a la clase rango y le asignamos una nueva variable que sera utilizada en el main y para que tome de referencia a la clase rango

	hostil.Honck(); //La variable hostil llama a la funcion Honck
	cout << hostil.covenant + " " + hostil.raza; //El programa imprime las variables hostil referenciadas a la clase covenant y raza
	return 0; 
}
*/
void pedirOracion();
int contVocales(char*);

char oracion[30];

int main() {
	pedirOracion();
	cout << "El numero de vocales en la oración es: " << contVocales(oracion) << endl;

	_getch();
	return 0;
}

void pedirOracion() {
	cout << "Digite la oracion: " << endl;
	cin.getline(oracion, 30, '\n');

	_strupr(oracion);
}

int contVocales(char* ora) {
	int contador = 0;
	while (*ora) {
		switch (*ora) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U': contador++;
		}
		ora++;
	}
	return contador;
}
