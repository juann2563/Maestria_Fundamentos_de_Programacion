#include <iostream>
#include <stdlib.h>

using namespace std;
// Se crea la clase Persona
class Persona
{
private:
    string nombre;
    int edad;
public:
    Persona(string, int); // Constructor
    ~Persona(); // destructor de objetos
    void mostrarPersona(); // método mostrarPersona
};
//Se hereda los métodos públicos de la clase Persona
class Alumno : public Persona // Clase hija
{
private://atributos
    string codigoAlumno;
    float notaFinal;
public:
    // constructor, se debe respectar el orden jerárquico
    Alumno(string, int, string, float);
    void mostrarAlumno();
};
//Constructor de la clase Persona(Clase padre)
Persona::Persona(string _nombre, int _edad)
{
    nombre = _nombre;
    edad = _edad;
}
// se crea el destructor de objetos
Persona::~Persona(){}
//Constructor de la clase alumno(clase hija)
/*Se deben pasar los datos en el mismo orden como están jerárquicamente
es decir, primero los de la clase padre y luego los de la clase hija,
tambien al decirle al constructor de la clase alumno(:Persona(_nombre,_edad)) estoy
diciendo que ya estos valores los heredo de la clase Persona*/
Alumno::Alumno(string _nombre, int _edad, string _codigoAlumno, float _notaFinal):Persona(_nombre,_edad)
{
    codigoAlumno = _codigoAlumno;
    notaFinal = _notaFinal;

}
// Métodos
void Persona::mostrarPersona()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
void Alumno::mostrarAlumno()
{
    mostrarPersona();
    cout << "Codigo alumno: " << codigoAlumno << endl;
    cout << "Notal final: " <<  notaFinal << endl;
}

int main()
{
    Alumno alumno1("Juan",20,"1214721110",15.6);
    // desde el objeto alumno se puede acceder a todos los métodos
    // de la clase Persona
    alumno1.mostrarAlumno();
    return 0;
}
