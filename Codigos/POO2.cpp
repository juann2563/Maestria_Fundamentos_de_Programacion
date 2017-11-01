#include <iostream>
#include <stdlib.h>
using namespace std;

//Se crea la clase persona
class Persona
{
private: //Atributos
    // con private encapsulo los atributos
    int edad;
    string nombre;
public:
    // Constructor: nos sirve para inicializar los atributos
    Persona(int _edad, string _ nombre)
    {
        edad = _edad;
        nombre = _nombre;
    } 
    // Se método leer
    void leer()
    {
        cout << "Soy " << nombre << " Y tengo " << edad << endl;
    }
    // se crea el método correr
    void correr()
    {
        cout << "Soy " << nombre << "Y estoy corriendo" << endl;

    }
};

int main()
{
    //Se crea el objeto p1
    Persona p1 = Persona(20,"Juan");
    // se accede al método correr
    p1.correr();
    return 0;
}
