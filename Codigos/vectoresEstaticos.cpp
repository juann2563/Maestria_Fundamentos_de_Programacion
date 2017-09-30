#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int* LlenarVector(int x[]);
int EntreIniyFin();
void MostrarVector(int x[]);
int busquedaMayor(int x[]);
void repetido(int x[]);
int i, t, v1, v2;
int aux = 0;
int main()
{
    do{
        cout << "Digite el tamno del vector: ";
        cin >> t;
        cout << "Digite el valor del rango minimo: ";
        cin >> v1;
        cout << "Digite el valor del rango maaimo: ";
        cin >> v2;
        if(t <= 0 || v1 >= v2){
            cout << "el tamaño del vector o el tamano no es valido" << endl;
        }
    }while(t <=0 || v1 >= v2);
    int vect[t];
    LlenarVector(vect);
    MostrarVector(vect);
    int mayor = busquedaMayor(vect);
    cout << "El mayor es: " << mayor << endl;
    repetido(vect);
    return 0;
}
// función para llenar el vector
int* LlenarVector(int x[]){
    srand((unsigned)time(NULL));
    for(i = 0; i<t; i++){
        x[i] = EntreIniyFin();
    }
    return x;
}
int EntreIniyFin(){
    int Dif = v2 - v1;
    int Ng = v1 + (rand()%(Dif+1));
    return Ng;
}
void MostrarVector(int x[]){
    string Rpta = "";
    for(i = 0; i < t; i++) //x.size()
    {
        cout << endl << "[" << x[i] << "]" << endl;
    }
}
int busquedaMayor(int x[]){
    for(i = 0; i<t; i++){
        if(x[i]>aux){
            aux = x[i];
        }
    }
    return aux;
}
void repetido(int x[]){
    int cont = 0;
    for(int i = 0; i<t; i++)
    {
        if(x[i] == aux){
          cont++;
        }
    }
    int posiciones[cont];
    int auxCont = 0;
    for(i = 0; i<t; i++){
        if(x[i]==aux){
            posiciones[auxCont]=i;
            auxCont++;
        }
    }
    cout << "Cantidad de veces repetidas: " << cont <<endl;
    cout << "Posiciones repetidas: ";
    for(i = 0; i<cont; i++){
        cout << posiciones[i]+1 << " ";
    }
}
