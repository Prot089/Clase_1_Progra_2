// Polimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    std::string nombre;
    int edad;
public:
    Persona(string, int); // Declaracion de constructor de persona
    virtual void mostrar(); //Metodo virtual, con estp podemos trabajar con polimorfismo en c++
};

Persona::Persona(string _nombre, int _edad) { // Asignamos valores al constructor
    nombre = _nombre; //Asignamos el valor que estamos declarando en el constructor a las variables propias de la clase
    edad = _edad;
};

void Persona::mostrar() { //Definimos el comportamiento de la funcion o metodo de persona
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    if (edad >= 18) {
        cout << "Es mayor de edad" << endl;
    }
}

class Alumno : public Persona {
private:
    float calificacion;
public:
    Alumno(string, int, float);
    void mostrar();
};

Alumno::Alumno(string _nombre, int _edad, float _calificacion) : Persona( _nombre,  _edad) {
calificacion = _calificacion;
};

void Alumno::mostrar() {
    Persona::mostrar();
    cout << "Calificacion: " << calificacion << endl;
};

class Profesor : public Persona {
private:
    string materia;
public:
    Profesor(string, int, string);
    void mostrar();
};

Profesor::Profesor(string _nombre, int _edad, string _materia) : Persona(_nombre, _edad) {
    materia = _materia;
}

void Profesor::mostrar() {
    Persona::mostrar();
    cout << "Material: " << materia << endl;
}

int main() {
    Persona* Arreglo[4]; //Puntero de persona
    Arreglo[0] = new Alumno("Oscar", 21,8.9); //Definimos un nuevo tipo de Alumno que ereda de persona y ademas asignamos 
    Arreglo[1] = new Alumno("Jair", 25, 9);
    Arreglo[2] = new Alumno("Israel", 22,  7.9);
    Arreglo[3] = new Profesor("Miguel", 30, "Tecnologias de la programacion");

    Arreglo[0]->mostrar();
    cout << "\n";
    Arreglo[1]->mostrar();
    cout << "\n";
    Arreglo[2]->mostrar();
    cout << "\n";
    Arreglo[3]->mostrar();
    cout << "\n";
}