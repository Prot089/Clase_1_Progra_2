// Proyecto juego progra 2 parcial 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;
enum enem { aracnia = 1, aracnio=2, aracnie=3, eskeler=4, eskeletor=5, dracula=6, orco=7 };

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
	int vida = 40;
	int vidaaracnia = 6;
	int vidaaracnio = 6;
	int vidaaracnie = 6;
	int vidaeskeler = 12;
	int vidaeskeletor = 12;
	int vidadracula = 25;
	int vidaorco = 50;
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

	vector[0] = new Enemigo("Aracnia", 3, 6, "Normal");
	vector[1] = new Enemigo("Aracnio", 3, 6, "Normal");
	vector[2] = new Enemigo("Aracnie", 3, 6, "Normal");
	vector[3] = new Enemigo("Eskeler", 4, 12, "Normal");
	vector[4] = new Enemigo("Eskeletor", 4, 12, "Normal");
	vector[5] = new Enemigo("Dracula", 6, 25, "Especial");
	vector[6] = new Enemigo("Orchundus, el orco", 8, 50, "Jefe");
	vector[7] = new Heroe(name, 40, 4, 3);
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

	cout << "Esta es tu bolsa, en ella puedes ingresar codigos de objeto al derrotar bosses." << endl;
	menu();
	
	cout << "Deberiamos comenzar por matar a las aranas en el bosque maldito, puedes ganar experiencia y aprender a combatir." << endl;
	while (salir == false, vida >=1) {

	cout << "Vamos a cazarlo!" << endl;
	cout << "Tu oponente es Aracnia" << endl;
	vector[0]->mostrar();
		while (vida >= 1, vidaaracnia >= 1) {
			cout << "\tPelea!" << endl;
			cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger" << endl;
			cin >> opcmov;

			switch (opcmov)
			{
			case 1:
				cout << "\tSeleccionaste Espada" << endl;
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
				cout << "\tEl enemigo ha elegido Mordida" << endl;
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
		else if (vida <= 1)
		{
			cout << "\tPerdiste" << endl;
		}
		cout << "\tCodigo de trofeo: 12\nEsa fue la primer arana en este bosque maldito, vamos a buscar mas, viajero.\nNo bajes la guardia, aun quedan muchas amenazas en este bosque." << endl;
		cout << "Vida:" << vida << endl;
		cout << "Vamos, escribe el codigo que solto Aracnia" << endl;
		menu();
		cout << "Quieres continuar?\n1 = Si\n0=No" << endl;
		cin >> opc;
		if (opc == 1) {
			cout << "Vamos a cazarlo!" << endl;
			cout << "Tu oponente es Aracnio" << endl;
			vector[1]->mostrar();
			while (vida >= 1, vidaaracnio >= 1) {
				cout << "\tPelea!" << endl;
				cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger" << endl;
				cin >> opcmov;

				switch (opcmov)
				{
				case 1:
					cout << "\tSeleccionaste Espada" << endl;
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
					cout << "\tEl enemigo ha elegido Mordida" << endl;
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
				cout << "\tSencillo, no crees?" << endl;
			}
			else if (vida <= 1)
			{
				cout << "\tWow, eso no me lo esperaba, intentalo de nuevo:)" << endl;
			}
			cout << "Codigo: 23\nLa desesperacion de tus enemigos se hace mas grande, ya has eliminado a 2 de sus monstruos mas poderosos en el bosque.";
			cout << "Vida:" << vida << endl;
			cout << "Vamos, escribe el codigo que solto Aracnio" << endl;
			menu();
			cout << "Quieres continuar?\n1 = Si\n0=No" << endl;
			cin >> opc;
			if (opc == 1) {
				cout << "Acabemos con esto." << endl;
				cout << "Tu oponente es Aracnie" << endl;
				vector[2]->mostrar();
				while (vida >= 1, vidaaracnie >= 1) {
					cout << "\tPelea!" << endl;
					cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger" << endl;
					cin >> opcmov;

					switch (opcmov)
					{
					case 1:
						cout << "\tSeleccionaste Espada" << endl;
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
						cout << "\tEl enemigo ha elegido Mordida" << endl;
						vida -= 3;
					}
					else
					{
						cout << "\tEl enemigo ha utilizado Proteger" << endl;
						vidaaracnie += 2;
					}
					cout << "\tTu vida es de " << vida << endl;
					cout << "\tLa vida de tu enemigo es de " << vidaaracnie << endl;
				}
				if (vidaaracnie <= 0)
				{
					cout << "\tSencillo, no crees?" << endl;
				}
				else if (vida <= 1)
				{
					cout << "\tWow, eso no me lo esperaba, intentalo de nuevo:)" << endl;
				}
				cout << "Vida:" << vida << endl;
				cout << "Codigo: 45" << endl;
				cout << "Has subido tus estadisticas viajero!\nAhora tu vida es de: " << vida + 5 <<" puntos"<< endl;
				cout << "Y tu ataque subio a: 6 puntos!" << endl;
				cout << "Ahora que ya estas familiarizado con el sistema de combate y tienes mejores stats para defenderte, dirijamonos al castillo embrujado donde se encuentra Orchundus, el orco." << endl;
				cout << "Seran enfrentamientos muy voraces, pero valdran la pena, " << name << endl;
				cout << "Vamos, escribe el codigo que solto Aracnie" << endl;
				menu();
				cout << "Quieres continuar?\n1 = Si\n0=No" << endl;
				cin >> opc;
				if (opc == 1) {
					cout << "Tu oponente es Eskeler" << endl;
					vector[3]->mostrar();
					while (vida >= 1, vidaeskeler >= 1) {
						cout << "\tPelea!" << endl;
						cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger" << endl;
						cin >> opcmov;

						switch (opcmov)
						{
						case 1:
							cout << "\tSeleccionaste Espada" << endl;
							vidaeskeler -= 6;
							break;
						case 2:
							cout << "\tSeleccionaste Proteger" << endl;
							vida += 3;
							break;
						}
						num = rand() % (2);
						cout << num << " ";
						if (num == 0)
						{
							cout << "\tEl enemigo ha elegido Mordida" << endl;
							vida -= 4;
						}
						else
						{
							cout << "\tEl enemigo ha utilizado Proteger" << endl;
							vidaeskeler += 3;
						}
						cout << "\tTu vida es de " << vida << endl;
						cout << "\tLa vida de tu enemigo es de " << vidaeskeler << endl;
					}
					if (vidaeskeler <= 0)
					{
						cout << "\tSencillo, no crees?" << endl;
					}
					else if (vida <= 1)
					{
						cout << "\tWow, eso no me lo esperaba, intentalo de nuevo:)" << endl;
					}
					cout << "Vida:" << vida << endl;
					cout << "Codigo: 56" << endl;
					cout << "Estuviste estupendo contra ese saco de huesos, " << name << "vamos por el siguiente." << endl;
					cout << "Vamos, escribe el codigo que solto Eskeler" << endl;
					menu();
					cout << "Quieres continuar?\n1 = Si\n0=No" << endl;
					cin >> opc;
					if (opc == 1) {
						cout << "Vamos a cazarlo!" << endl;
						cout << "Tu oponente es Eskeletor" << endl;
						vector[4]->mostrar();
						while (vida >= 1, vidaeskeletor >= 1) {
							cout << "\tPelea!" << endl;
							cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger" << endl;
							cin >> opcmov;
							switch (opcmov)
							{
							case 1:
								cout << "\tSeleccionaste Espada" << endl;
								vidaeskeletor -= 6;
								break;
							case 2:
								cout << "\tSeleccionaste Proteger" << endl;
								vida += 3;
								break;
							}
							num = rand() % (2);
							cout << num << " ";
							if (num == 0)
							{
								cout << "\tEl enemigo ha elegido Mordida" << endl;
								vida -= 4;
							}
							else
							{
								cout << "\tEl enemigo ha utilizado Proteger" << endl;
								vidaeskeletor += 3;
							}
							cout << "\tTu vida es de " << vida << endl;
							cout << "\tLa vida de tu enemigo es de " << vidaeskeletor << endl;
						}
						if (vidaeskeletor <= 0)
						{
							cout << "\tSencillo, no crees?" << endl;
						}
						else if (vida <= 1)
						{
							cout << "\tWow, eso no me lo esperaba, intentalo de nuevo:)" << endl;
						}
						cout << "Vida:" << vida << endl;
						cout << "La siguiente puerta se ve bastante antigua, no se si deberiamos abrirla..." << endl;
						cout << "Codigo: 85" << endl;
						cout << "Vamos, escribe el codigo que solto Eskeletor" << endl;
						menu();
						cout << "Quieres continuar?\n1 = Si\n0=No" << endl;
						cin >> opc;
						if (opc) {
							cout << "Oh no, es el rey de las tinieblas..." << endl;
							cout << "Deberias tener cuidado, dale con la espada y reza por no morir..." << endl;
							cout << "Tu oponente es Aracnia" << endl;
							vector[5]->mostrar();
							while (vida >= 1, vidadracula >= 1) {
								cout << "\tPelea!" << endl;
								cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger" << endl;
								cin >> opcmov;

								switch (opcmov)
								{
								case 1:
									cout << "\tSeleccionaste Espada" << endl;
									vidadracula -= 6;
									break;
								case 2:
									cout << "\tSeleccionaste Proteger" << endl;
									vida += 6;
									break;
								}
								num = rand() % (2);
								cout << num << " ";
								if (num == 0)
								{
									cout << "\tEl enemigo ha elegido Mordida" << endl;
									vida -= 7;
								}
								else
								{
									cout << "\tEl enemigo ha utilizado Proteger" << endl;
									vidadracula += 3;
								}
								cout << "\tTu vida es de " << vida << endl;
								cout << "\tLa vida de tu enemigo es de " << vidadracula << endl;
							}
							if (vidadracula <= 0)
							{
								cout << "\tSencillo, no crees?" << endl;
							}
							else if (vida <= 1)
							{
								cout << "\tWow, eso no me lo esperaba, intentalo de nuevo:)" << endl;
							}
							cout << "Vida:" << vida << endl;
							cout << "Codigo: 50\nDracula solia ser un humano como nosotros, pero un pacto con una entidad desconocida lo hizo comenzar a matar" << endl;
							cout << "Descansa en paz, Dracula." << endl;
							cout << "Has subido tus estadisticas viajero!\nAhora tu vida es de: " << vida + 5 << " puntos" << endl;
							cout << "Y tu ataque subio a: 8 puntos!\nHas desbloqueado el ataque\n--Bola de fuego--\nDano: 10" << endl;
							cout << "Vamos, escribe el codigo que solto Dracula" << endl;
							menu();
							cout << "Quieres continuar?\n1 = Si\n0=No" << endl;
							cin >> opc;
							if (opc) {
								cout << "Recoge tus cosas y armate de valor, nos queda el ultimo jefe." << endl;
								cout << "Tu oponente es Orchundus, el Orco." << endl;
								vector[6]->mostrar();
								while (vida >= 1, vidaorco >= 1) {
									cout << "\tPelea!" << endl;
									cout << "\tElige tu proximo movimiento \n1-Espada\n2-Proteger\n3-Bola de fuego" << endl;
									cin >> opcmov;

									switch (opcmov)
									{
									case 1:
										cout << "\tSeleccionaste Espada" << endl;
										vidaorco -= 8;
										break;
									case 2:
										cout << "\tSeleccionaste Proteger" << endl;
										vida += 8;
										break;
									case 3:
										cout << "\tSeleccionaste Bola de fuego" << endl;
										vidaorco -= 10;
										break;
									}
									num = rand() % (2);
									cout << num << " ";
									if (num == 0)
									{
										cout << "\tEl enemigo ha elegido Mordida" << endl;
										vida -= 7;
									}
									else
									{
										cout << "\tEl enemigo ha utilizado Proteger" << endl;
										vidaorco += 4;
									}
									cout << "\tTu vida es de " << vida << endl;
									cout << "\tLa vida de tu enemigo es de " << vidaorco << endl;
								}
								if (vidaorco <= 0)
								{
									cout << "\tMira, que hay detras de su cadaver" << endl;
								}
								else if (vida <= 1)
								{
									cout << "\tPerdiste" << endl;
								}
								cout << "Al parecer, este orco defendia el castillo por lo que aqui albergaba\nSon.. son los restos de su familia." << endl;
								cout << "Vida:" << vida << endl;
								cout << "Vamos, escribe el codigo que solto Orchundus.\nCodigo: 100" << endl;
								menu();
							}
						}
					}
				}
			}
		}
		cout << "Gracias " << name << " eso fue mas oscuro de lo que pense, no crei que los enemigos se comportaran como nosotros..." << endl;
		cout << "Deseas jugar otra vez?" << endl;
		cout << "Responde 1 para si y 0 para no" << endl;
		cin >> salir;			
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
