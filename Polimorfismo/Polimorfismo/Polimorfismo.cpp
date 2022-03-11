// Polimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Omar Alejandro Angeles Hernandez

/*
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
    virtual void almorzar() = 0; // Metodo virtual puro
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
    virtual void almorzar() {
        cout << "Almuerzo a las 7" << endl;
    }
};

Alumno::Alumno(string _nombre, int _edad, float _calificacion) : Persona(_nombre, _edad) {
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
    virtual void almorzar() {
        cout << "Almuerzo a las 10" << endl;
    }
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
    try {
        int num1 = 9;
        int num2 = 0;

        cout << "Division" << num1 / num2 << endl;

    }
    catch (exception e) {
        cout << "Ocurrio un error " << endl;
    }


    Arreglo[0] = new Alumno("Oscar", 21, 8.9); //Definimos un nuevo tipo de Alumno que ereda de persona y ademas asignamos un nuevo valor
    Arreglo[1] = new Alumno("Jair", 25, 9);
    Arreglo[2] = new Alumno("Israel", 22, 7.9);
    Arreglo[3] = new Profesor("Miguel", 30, "Tecnologias de la programacion");

    Arreglo[0]->mostrar();
    cout << "\n";
    Arreglo[1]->mostrar();
    cout << "\n";
    Arreglo[2]->mostrar();
    cout << "\n";
    Arreglo[3]->mostrar();
    cout << "\n";
    Arreglo[3]->almorzar();
    cout << "\n";

    return 0;
}
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Figuras {
private:
    int nLados;
    string color;
public:
    Figuras(int, string);
    virtual void mostrar();
    virtual void area();
    virtual void perimetro();
};

Figuras::Figuras(int _nLados, string _color) {
    nLados = _nLados;
    color = _color;
}

void Figuras::mostrar() {
    cout << "Esta figura tiene: " << nLados << " lados." << endl;
    cout << "Color: " << color << endl;
}

class Circulo : public Figuras {
private:
    double radio;
    double pi = 3.1416;
public:
    Circulo(int, string, double, double);
    void mostrar();
    virtual void Area() {
        cout << "El area de este circulo es de: " << pow(radio, 2) * pi << endl;
    }
    virtual void Perimetro() {
        cout << "El perimetro de este circulo es de: " << radio * 2 * pi << endl;
    }
    
};

class Cuadrado : public Figuras {
private:
    int base;
    int altura;
public:
    Cuadrado(int, string, int, int);
    void mostrar();
    virtual void Area() {
        cout << "El area de este cuadrado es: " << base * altura << endl;
    }
    virtual void Perimetro() {
        cout << "El perimetro de este cuadrado es: " << base + base + altura + altura << endl;
    }
};

Cuadrado::Cuadrado(int _nLados, string _color, int _base, int _altura) :Figuras(_nLados, _color) {
    base = _base;
    altura = _altura;
}

void Cuadrado::mostrar() {
    Figuras::mostrar();
}

class triangulo : public Figuras {
private:
    double catetoop;
    double catetoad;
    double aux = pow(catetoad,2) + pow(catetoop,2);
public:
    triangulo(int, string, double, double, double);
    void mostrar();
    virtual void hipotenusa() {
        cout << "La hipotenusa de este triangulo es: " << sqrt(aux) << endl;
    }
    virtual void Area() {
        cout << "El area de este triangulo es: " << catetoad * catetoop / 2 << endl;
    }
    virtual void perimetro() {
        cout << "Su perimetro es de: " << catetoad + catetoop + hipotenusa() << endl;
    }
};

triangulo::triangulo(int _nLados, string _color, double _catetoad, double _catetoop, double _aux) :Figuras(_nLados, _color) {
    catetoad = _catetoad;
    catetoop = _catetoop;
    aux = _aux;
}

void triangulo::mostrar() {
    Figuras::mostrar();
}

int main()
{
    Figuras* Arreglo[3];

    Arreglo[0] new Cuadrado(4, "Azul", 4, 4);
    Arreglo[1] new Circulo(1, "Rojo", 3);
    Arreglo[2] new Triangulo(3, "Verde", 4, 5);
}