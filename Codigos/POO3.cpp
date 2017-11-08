#include <iostream>
#include <stdlib.h>
using namespace std;

class Fecha
{
    int dia, mes, anio;
public:
    //Constructor 1
    Fecha(int _dia,int _mes, int _anio)
    {
        dia = _dia;
        mes = _mes;
        anio = _anio;
    }
    // constructor 2
    Fecha(long fecha)
    {
        anio = int(fecha/10000); // extraer año
        mes = int((fecha-anio*10000)/100); // extraer el mes
        dia = int(fecha-anio*10000-mes*100); // extraer el día
    }

    void mostrarFecha()
    {
        cout << "La fecha es: " << dia << "/" << mes << "/" << anio << endl;
    }
};
int main()
{
    // se crea el objeto hoy
    Fecha hoy(1,11,2017);
    Fecha ayer(20170105);
    hoy.mostrarFecha();
    ayer.mostrarFecha();
    return 0;
}
