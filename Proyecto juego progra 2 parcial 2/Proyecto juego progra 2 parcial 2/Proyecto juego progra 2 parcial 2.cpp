// Proyecto juego progra 2 parcial 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
enum enem { aracnia = 1, aracnio, aracnie, eskeler, eskeletor, dracula, orco };

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

class Personajes {
private:
	string nombre;
	int hp, fuerza;
public:
	Personajes(string, int, int);
	virtual void mostrar();
};

class Enemigo :public Personajes {
private: 
	string rango;
public:
	Enemigo(string, int, int, string);
	void mostrar();
};

class Heroe :public Personajes {
private:
	int vidas;
public:
	Heroe(string, int, int, int);
	void mostrar();
};

Personajes::Personajes(string _nombre, int _fuerza, int _hp) {
	nombre = _nombre;
	fuerza = _fuerza;
	hp = _hp;
}

Enemigo::Enemigo(string _nombre, int _fuerza, int _hp, string _rango): Personajes(_nombre, _fuerza, _hp) {
	rango = _rango;
}

Heroe::Heroe(string _nombre, int _fuerza, int _hp, int _vidas) : Personajes(_nombre, _fuerza, _hp) {
	vidas = _vidas;
}

void Personajes::mostrar() {
	cout << "Nombre: " << nombre << endl;
	cout << "Fuerza " << fuerza << endl;
	cout << "Vida: " << hp << endl;
}

void Enemigo::mostrar() {
	Personajes::mostrar();
	cout << "Es una Enemigo de rango: " << rango << endl;
}

void Heroe::mostrar() {
	Personajes::mostrar();
	cout << "Tu heroe tiene " << vidas << " vidas"<<  endl;
}

int main()
{
	bool salir = false;
	int opcmov = 0;
	int rival;
	int vida = 25;
	int vidaaracnia = 5;
	int vidaaracnio = 5;
	int vidaaracnie = 5;
	int vidaeskeler = 6;
	int vidaeskeletor = 6;
	int vidadracula = 15;
	int vidaorco = 20;
	int num;
	int opc = 0;
	srand(time(NULL));
	int i = 0;
	bool bolsa = true;
	string name;

	cout << "Hola viajero, como te llamas?" << endl;
	cin >> name;
	cout << "Bienvenido " << name << endl;
	cout << "Esto es un campo de entrenamiento, es muy similar a un enfrentamiento por hordas pero de uno a uno, ganales a los enemigos que quieras para descurbir algo especial" << endl;

	Personajes* vector[8];

	vector[0] = new Enemigo("Aracnia", 3, 5, "Normal");
	vector[1] = new Enemigo("Aracnio", 3, 5, "Normal");
	vector[2] = new Enemigo("Aracnie", 3, 5, "Normal");
	vector[3] = new Enemigo("Eskeler", 4, 6, "Normal");
	vector[4] = new Enemigo("Eskeletor", 4, 6, "Normal");
	vector[5] = new Enemigo("Dracula", 15, 6, "Especial");
	vector[6] = new Enemigo("Orchundus, el orco", 20, 7, "Jefe");
	vector[7] = new Heroe(name, 25, 4, 3);
	vector[0]->mostrar();
	vector[1]->mostrar();
	vector[2]->mostrar();
	vector[3]->mostrar();
	vector[4]->mostrar();
	vector[5]->mostrar();
	vector[6]->mostrar();
	vector[7]->mostrar();

	cout << "\n";
	cout << "\tToma esta espada y armadura. Ahora este eres tu" << endl;
	vector[4]->mostrar();

	cout << "Antes de partir, agrega algunos objetos a tu bolsa." << endl;
	cout << "Pocima de salud - 1\nPocima de fuerza - 2" << endl;
	menu();

	cout << "A donde te gustaria ir en tu proxima aventura?" << endl;
	cout << "1- Aracnia\t2- Aracnio\t3- Aracnie\t4- Eskeler\t5- Eskeletor\t6-Dracula\t7- Orchundus, el orco."<<endl;
	cin >> opc;

	while (salir == false) {


		switch (opc)
		{

		case aracnia:
			cout << "Vamos a cazarlo!" << endl;
			rival = aracnia;
			cout << "Tu oponente es Aracnia" << endl;
			vector[0]->mostrar();
			while (vida >= 1, vidaaracnia >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidaaracnia -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 3;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidaaracnia += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidaaracnia << endl;
			}
			if (vidaaracnia <= 0)
			{
				cout << "\tSencillo, no crees?" << endl;
			}
			else
			{
				cout << "\tWow, eso no me lo esperaba, intentalo de nuevo:)" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			else {
				cout << "A donde te gustaria ir en tu proxima aventura?" << endl;
			}
			cout << "2- Aracnio\t3- Aracnie\t4- Eskeler\t5- Eskeletor\t6-Dracula\t7- Orchundus, el orco.";
			cin >> opc;
			switch (opc) {
			case aracnio:
				cout << "Vamos a cazarlo!" << endl;
				rival = aracnio;
				cout << "Tu oponente es Aracnio" << endl;
				vector[1]->mostrar();
				while (vida >= 1, vidaaracnio >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaaracnio -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 3;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaaracnio += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaaracnio << endl;
				}
				if (vidaaracnio <= 0)
				{
					cout << "\tEso es todo de su parte? apenas vas comenzando!" << endl;
				}
				else
				{
					cout << "\tTrae un raid la proxima vez" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				cout << "A donde te gustaria ir en tu proxima aventura?" << endl;
				cout << "\t3- Aracnie\t4- Eskeler\t5- Eskeletor\t6-Dracula\t7- Orchundus, el orco.";
				cin >> opc;
				switch (opc) {
				case aracnie:
					cout << "Vamos a cazarlo!" << endl;
					rival = aracnie;
					cout << "Tu oponente es Aracnie" << endl;
					vector[3]->mostrar();
					cout << "Vamos a cazarlo!" << endl;
					rival = aracnio;
					cout << "Tu oponente es Aracnio" << endl;
					vector[1]->mostrar();
					while (vida >= 1, vidaaracnie >= 1) {
						cout << "\tPelea!" << endl;
						cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
						cin >> opcmov;

						switch (opcmov)
						{
						case 1:
							cout << "\tSeleccionaste Derribo" << endl;
							vidaaracnie -= 4;
							break;
						case 2:
							cout << "\tSeleccionaste Proteger" << endl;
							vida += 2;
							break;
						}
						num = rand() % (2);
						cout << num << " ";
						if (num == 0)
						{
							cout << "\tEl enemigo ha elegido Derribo" << endl;
							vida -= 3;
						}
						else
						{
							cout << "\tEl enemigo ha utilizado Proteger" << endl;
							vidaaracnio += 2;
						}
						cout << "\tTu vida es de " << vida << endl;
						cout << "\tLa vida de tu enemigo es de " << vidaaracnie << endl;
					}
					if (vidaaracnie <= 0)
					{
						cout << "\tAranas, odio las aranas" << endl;
					}
					else
					{
						cout << "\tNo te rindas!" << endl;
					}
					cout << "Vida:" << vida << endl;

					cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
					cout << "Si = 1\nNo = 0: " << endl;
					cin >> bolsa;
					if (bolsa == 1) {
						menu();
					}
					break;
					getchar();

				case eskeler:
					cout << "Vamos a cazarlo!" << endl;
					rival = eskeler;
					cout << "Tu oponente es Eskeler" << endl;
					vector[4]->mostrar();
					cout << "Vamos a cazarlo!" << endl;
					while (vida >= 1, vidaeskeler >= 1) {
						cout << "\tPelea!" << endl;
						cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
						cin >> opcmov;

						switch (opcmov)
						{
						case 1:
							cout << "\tSeleccionaste Derribo" << endl;
							vidaeskeler -= 4;
							break;
						case 2:
							cout << "\tSeleccionaste Proteger" << endl;
							vida += 2;
							break;
						}
						num = rand() % (2);
						cout << num << " ";
						if (num == 0)
						{
							cout << "\tEl enemigo ha elegido Derribo" << endl;
							vida -= 4;
						}
						else
						{
							cout << "\tEl enemigo ha utilizado Proteger" << endl;
							vidaeskeler += 2;
						}
						cout << "\tTu vida es de " << vida << endl;
						cout << "\tLa vida de tu enemigo es de " << vidaeskeler << endl;
					}
					if (vidaeskeler <= 0)
					{
						cout << "\tNada mal, destruiste el cuerpo impuro de un cantante de hace siglos" << endl;
					}
					else
					{
						cout << "\tPerdiste" << endl;
					}
					cout << "Vida:" << vida << endl;

					cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
					cout << "Si = 1\nNo = 0: " << endl;
					cin >> bolsa;
					if (bolsa == 1) {
						menu();
					}
					break;
					getchar();
				case eskeletor:
					cout << "Vamos a cazarlo!" << endl;
					rival = eskeletor;
					cout << "Tu oponente es Eskeletor" << endl;
					vector[5]->mostrar();
					while (vida >= 1, vidaeskeletor >= 1) {
						cout << "\tPelea!" << endl;
						cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
						cin >> opcmov;

						switch (opcmov)
						{
						case 1:
							cout << "\tSeleccionaste Derribo" << endl;
							vidaeskeletor -= 4;
							break;
						case 2:
							cout << "\tSeleccionaste Proteger" << endl;
							vida += 2;
							break;
						}
						num = rand() % (2);
						cout << num << " ";
						if (num == 0)
						{
							cout << "\tEl enemigo ha elegido Derribo" << endl;
							vida -= 4;
						}
						else
						{
							cout << "\tEl enemigo ha utilizado Proteger" << endl;
							vidaeskeletor += 2;
						}
						cout << "\tTu vida es de " << vida << endl;
						cout << "\tLa vida de tu enemigo es de " << vidaeskeletor << endl;
					}
					if (vidaeskeletor <= 0)
					{
						cout << "\tQuizas a tu perro le gusten sus huesos." << endl;
					}
					else
					{
						cout << "\tPerdiste" << endl;
					}
					cout << "Vida:" << vida << endl;

					cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
					cout << "Si = 1\nNo = 0: " << endl;
					cin >> bolsa;
					if (bolsa == 1) {
						menu();
					}
					break;
					getchar();
				case dracula:
					cout << "Vamos a cazarlo!" << endl;
					rival = dracula;
					cout << "Tu oponente es Dracula" << endl;
					vector[6]->mostrar();
					while (vida >= 1, vidadracula >= 1) {
						cout << "\tPelea!" << endl;
						cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
						cin >> opcmov;

						switch (opcmov)
						{
						case 1:
							cout << "\tSeleccionaste Derribo" << endl;
							vidadracula -= 4;
							break;
						case 2:
							cout << "\tSeleccionaste Proteger" << endl;
							vida += 2;
							break;
						}
						num = rand() % (2);
						cout << num << " ";
						if (num == 0)
						{
							cout << "\tEl enemigo ha elegido Derribo" << endl;
							vida -= 6;
						}
						else
						{
							cout << "\tEl enemigo ha utilizado Proteger" << endl;
							vidadracula += 2;
						}
						cout << "\tTu vida es de " << vida << endl;
						cout << "\tLa vida de tu enemigo es de " << vidadracula << endl;
					}
					if (vidadracula <= 0)
					{
						cout << "\tDracula alguna vez fue un hombre muy importante para su pueblo, que mal que la sangre lo haya hecho perder el camino socialmente aceptable" << endl;
					}
					else
					{
						cout << "\tPerdiste" << endl;
					}
					cout << "Vida:" << vida << endl;

					cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
					cout << "Si = 1\nNo = 0: " << endl;
					cin >> bolsa;
					if (bolsa == 1) {
						menu();
					}
					break;
					getchar();
				case orco:
					cout << "Vamos a cazarlo!" << endl;
					rival = orco;
					cout << "Tu oponente es Orchundus, el orco." << endl;
					vector[7]->mostrar();
					while (vida >= 1, vidaorco >= 1) {
						cout << "\tPelea!" << endl;
						cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
						cin >> opcmov;

						switch (opcmov)
						{
						case 1:
							cout << "\tSeleccionaste Derribo" << endl;
							vidaorco -= 4;
							break;
						case 2:
							cout << "\tSeleccionaste Proteger" << endl;
							vida += 2;
							break;
						}
						num = rand() % (2);
						cout << num << " ";
						if (num == 0)
						{
							cout << "\tEl enemigo ha elegido Derribo" << endl;
							vida -= 7;
						}
						else
						{
							cout << "\tEl enemigo ha utilizado Proteger" << endl;
							vidaorco += 2;
						}
						cout << "\tTu vida es de " << vida << endl;
						cout << "\tLa vida de tu enemigo es de " << vidaorco << endl;
					}
					if (vidaorco <= 0)
					{
						cout << "\tEste orco antes tenia una familia a la cual no pudo proteger de monstruos como tu. Ahora descansa en paz junto a ellos" << endl;
					}
					else
					{
						cout << "\tPerdiste" << endl;
					}
					cout << "Vida:" << vida << endl;

					cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
					cout << "Si = 1\nNo = 0: " << endl;
					cin >> bolsa;
					if (bolsa == 1) {
						menu();
					}
					break;
					getchar();
				}
				break;
				getchar();

			case aracnio:
				cout << "Vamos a cazarlo!" << endl;
				rival = aracnio;
				cout << "Tu oponente es Aracnio" << endl;
				vector[1]->mostrar();
				while (vida >= 1, vidaaracnio >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaaracnio -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 3;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaaracnio += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaaracnio << endl;
				}
				if (vidaaracnio <= 0)
				{
					cout << "\tEso es todo de su parte? apenas vas comenzando!" << endl;
				}
				else
				{
					cout << "\tTrae un raid la proxima vez" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case aracnie:
				cout << "Vamos a cazarlo!" << endl;
				rival = aracnie;
				cout << "Tu oponente es Aracnie" << endl;
				vector[3]->mostrar();
				cout << "Vamos a cazarlo!" << endl;
				rival = aracnio;
				cout << "Tu oponente es Aracnio" << endl;
				vector[1]->mostrar();
				while (vida >= 1, vidaaracnie >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaaracnie -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 3;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaaracnio += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaaracnie << endl;
				}
				if (vidaaracnie <= 0)
				{
					cout << "\tAranas, odio las aranas" << endl;
				}
				else
				{
					cout << "\tNo te rindas!" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();

			case eskeler:
				cout << "Vamos a cazarlo!" << endl;
				rival = eskeler;
				cout << "Tu oponente es Eskeler" << endl;
				vector[4]->mostrar();
				cout << "Vamos a cazarlo!" << endl;
				while (vida >= 1, vidaeskeler >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaeskeler -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 4;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaeskeler += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaeskeler << endl;
				}
				if (vidaeskeler <= 0)
				{
					cout << "\tNada mal, destruiste el cuerpo impuro de un cantante de hace siglos" << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case eskeletor:
				cout << "Vamos a cazarlo!" << endl;
				rival = eskeletor;
				cout << "Tu oponente es Eskeletor" << endl;
				vector[5]->mostrar();
				while (vida >= 1, vidaeskeletor >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaeskeletor -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 4;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaeskeletor += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaeskeletor << endl;
				}
				if (vidaeskeletor <= 0)
				{
					cout << "\tQuizas a tu perro le gusten sus huesos." << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case dracula:
				cout << "Vamos a cazarlo!" << endl;
				rival = dracula;
				cout << "Tu oponente es Dracula" << endl;
				vector[6]->mostrar();
				while (vida >= 1, vidadracula >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidadracula -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 6;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidadracula += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidadracula << endl;
				}
				if (vidadracula <= 0)
				{
					cout << "\tDracula alguna vez fue un hombre muy importante para su pueblo, que mal que la sangre lo haya hecho perder el camino socialmente aceptable" << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case orco:
				cout << "Vamos a cazarlo!" << endl;
				rival = orco;
				cout << "Tu oponente es Orchundus, el orco." << endl;
				vector[7]->mostrar();
				while (vida >= 1, vidaorco >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaorco -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 7;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaorco += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaorco << endl;
				}
				if (vidaorco <= 0)
				{
					cout << "\tEste orco antes tenia una familia a la cual no pudo proteger de monstruos como tu. Ahora descansa en paz junto a ellos" << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();

				}
				break;
				getchar();
			case aracnie:
				cout << "Vamos a cazarlo!" << endl;
				rival = aracnie;
				cout << "Tu oponente es Aracnie" << endl;
				vector[3]->mostrar();
				cout << "Vamos a cazarlo!" << endl;
				rival = aracnio;
				cout << "Tu oponente es Aracnio" << endl;
				vector[1]->mostrar();
				while (vida >= 1, vidaaracnie >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaaracnie -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 3;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaaracnio += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaaracnie << endl;
				}
				if (vidaaracnie <= 0)
				{
					cout << "\tAranas, odio las aranas" << endl;
				}
				else
				{
					cout << "\tNo te rindas!" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();

			case eskeler:
				cout << "Vamos a cazarlo!" << endl;
				rival = eskeler;
				cout << "Tu oponente es Eskeler" << endl;
				vector[4]->mostrar();
				cout << "Vamos a cazarlo!" << endl;
				while (vida >= 1, vidaeskeler >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaeskeler -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 4;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaeskeler += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaeskeler << endl;
				}
				if (vidaeskeler <= 0)
				{
					cout << "\tNada mal, destruiste el cuerpo impuro de un cantante de hace siglos" << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case eskeletor:
				cout << "Vamos a cazarlo!" << endl;
				rival = eskeletor;
				cout << "Tu oponente es Eskeletor" << endl;
				vector[5]->mostrar();
				while (vida >= 1, vidaeskeletor >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaeskeletor -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 4;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaeskeletor += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaeskeletor << endl;
				}
				if (vidaeskeletor <= 0)
				{
					cout << "\tQuizas a tu perro le gusten sus huesos." << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case dracula:
				cout << "Vamos a cazarlo!" << endl;
				rival = dracula;
				cout << "Tu oponente es Dracula" << endl;
				vector[6]->mostrar();
				while (vida >= 1, vidadracula >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidadracula -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 6;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidadracula += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidadracula << endl;
				}
				if (vidadracula <= 0)
				{
					cout << "\tDracula alguna vez fue un hombre muy importante para su pueblo, que mal que la sangre lo haya hecho perder el camino socialmente aceptable" << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			case orco:
				cout << "Vamos a cazarlo!" << endl;
				rival = orco;
				cout << "Tu oponente es Orchundus, el orco." << endl;
				vector[7]->mostrar();
				while (vida >= 1, vidaorco >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Derribo" << endl;
						vidaorco -= 4;
						break;
					case 2:
						cout << "\tSeleccionaste Proteger" << endl;
						vida += 2;
						break;
					}
					num = rand() % (2);
					cout << num << " ";
					if (num == 0)
					{
						cout << "\tEl enemigo ha elegido Derribo" << endl;
						vida -= 7;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaorco += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaorco << endl;
				}
				if (vidaorco <= 0)
				{
					cout << "\tEste orco antes tenia una familia a la cual no pudo proteger de monstruos como tu. Ahora descansa en paz junto a ellos" << endl;
				}
				else
				{
					cout << "\tPerdiste" << endl;
				}
				cout << "Vida:" << vida << endl;

				cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
				cout << "Si = 1\nNo = 0: " << endl;
				cin >> bolsa;
				if (bolsa == 1) {
					menu();
				}
				break;
				getchar();
			}
			break;
			getchar();

		case aracnio:
			cout << "Vamos a cazarlo!" << endl;
			rival = aracnio;
			cout << "Tu oponente es Aracnio" << endl;
			vector[1]->mostrar();
			while (vida >= 1, vidaaracnio >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidaaracnio -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 3;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidaaracnio += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidaaracnio << endl;
			}
			if (vidaaracnio <= 0)
			{
				cout << "\tEso es todo de su parte? apenas vas comenzando!" << endl;
			}
			else
			{
				cout << "\tTrae un raid la proxima vez" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			break;
			getchar();
		case aracnie:
			cout << "Vamos a cazarlo!" << endl;
			rival = aracnie;
			cout << "Tu oponente es Aracnie" << endl;
			vector[3]->mostrar();
			cout << "Vamos a cazarlo!" << endl;
			rival = aracnio;
			cout << "Tu oponente es Aracnio" << endl;
			vector[1]->mostrar();
			while (vida >= 1, vidaaracnie >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidaaracnie -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 3;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidaaracnio += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidaaracnie << endl;
			}
			if (vidaaracnie <= 0)
			{
				cout << "\tAranas, odio las aranas" << endl;
			}
			else
			{
				cout << "\tNo te rindas!" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			break;
			getchar();

		case eskeler:
			cout << "Vamos a cazarlo!" << endl;
			rival = eskeler;
			cout << "Tu oponente es Eskeler" << endl;
			vector[4]->mostrar();
			cout << "Vamos a cazarlo!" << endl;
			while (vida >= 1, vidaeskeler >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidaeskeler -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 4;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidaeskeler += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidaeskeler << endl;
			}
			if (vidaeskeler <= 0)
			{
				cout << "\tNada mal, destruiste el cuerpo impuro de un cantante de hace siglos" << endl;
			}
			else
			{
				cout << "\tPerdiste" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			break;
			getchar();
		case eskeletor:
			cout << "Vamos a cazarlo!" << endl;
			rival = eskeletor;
			cout << "Tu oponente es Eskeletor" << endl;
			vector[5]->mostrar();
			while (vida >= 1, vidaeskeletor >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidaeskeletor -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 4;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidaeskeletor += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidaeskeletor << endl;
			}
			if (vidaeskeletor <= 0)
			{
				cout << "\tQuizas a tu perro le gusten sus huesos." << endl;
			}
			else
			{
				cout << "\tPerdiste" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			break;
			getchar();
		case dracula:
			cout << "Vamos a cazarlo!" << endl;
			rival = dracula;
			cout << "Tu oponente es Dracula" << endl;
			vector[6]->mostrar();
			while (vida >= 1, vidadracula >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidadracula -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 6;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidadracula += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidadracula << endl;
			}
			if (vidadracula <= 0)
			{
				cout << "\tDracula alguna vez fue un hombre muy importante para su pueblo, que mal que la sangre lo haya hecho perder el camino socialmente aceptable" << endl;
			}
			else
			{
				cout << "\tPerdiste" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			break;
			getchar();
		case orco:
			cout << "Vamos a cazarlo!" << endl;
			rival = orco;
			cout << "Tu oponente es Orchundus, el orco." << endl;
			vector[7]->mostrar();
			while (vida >= 1, vidaorco >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Derribo \n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Derribo" << endl;
					vidaorco -= 4;
					break;
				case 2:
					cout << "\tSeleccionaste Proteger" << endl;
					vida += 2;
					break;
				}
				num = rand() % (2);
				cout << num << " ";
				if (num == 0)
				{
					cout << "\tEl enemigo ha elegido Derribo" << endl;
					vida -= 7;
				}
				else
				{
					cout << "\tEl enemigo ha utilizado Proteger" << endl;
					vidaorco += 2;
				}
				cout << "\tTu vida es de " << vida << endl;
				cout << "\tLa vida de tu enemigo es de " << vidaorco << endl;
			}
			if (vidaorco <= 0)
			{
				cout << "\tEste orco antes tenia una familia a la cual no pudo proteger de monstruos como tu. Ahora descansa en paz junto a ellos" << endl;
			}
			else
			{
				cout << "\tPerdiste" << endl;
			}
			cout << "Vida:" << vida << endl;

			cout << "Deseas usar/ingresar objetos a tu bolsa?" << endl;
			cout << "Si = 1\nNo = 0: " << endl;
			cin >> bolsa;
			if (bolsa == 1) {
				menu();
			}
			break;
			getchar();

			cout << "Deseas jugar otra vez?" << endl;
			cout << "Responde 0 para si y 1 para no" << endl;
			cin >> salir;
		}
	}
}

void menu() {
	int opcion, dato;
	do {
		cout << "\t.:Inventario:.\n";
		cout << "1. Agregar objeto\n";
		cout << "2. Mostrar objetos\n";
		cout << "3. Buscar objeto\n";
		cout << "4. Usar objeto\n";
		cout << "5. Salir\n";
		cin >> opcion;

		switch (opcion) {
		case 1: cout << "Agregue un objeto: " << endl;
			cin >> dato;
			insertLista(lista, dato);
			cout << "\n";
			system("pause");
			break;

		case 2: mostrarLista(lista);
			cout << "\n";
			system("pause");
			break;
		case 3: cout << "\nDigite el codigo del objeto a buscar: ";
			cin >> dato;
			buscarLista(lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 4: cout << "\nDigite el codigo del objeto que desea usar: ";
			cin >> dato;
			eliminarNodo(lista, dato);
			cout << "\n";
			system("pause");
			break;
		}

		system("cls");
	} while (opcion != 5);
}

void insertLista(Nodo*& lista, int n) {
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

	cout << "Objeto " << n << " agregado correctamente\n";
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
		cout << "Objeto " << n << "Si a sido encontrado en el inventario\n";
	}
	else {
		cout << "Objeto " << n << "No ha sido encontrado en el inventario\n";
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
			cout << "No sientes ningun cambio al ingerirlo" << endl;
		}
		//El elemento no ha sido encontrado
		if (aux_borrar == NULL) {
			cout << "No puedes usar un objeto que no tienes";
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