#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipos de Función
void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&,int &);

int main(){
    Nodo *pila = NULL;	//Inicializamos pila
    Nodo *pila2 = NULL;
    Nodo *pila3 = NULL;
    int datos1[5] = {1,2,3,4,5};
    int datos2[5] = {6,7,8,9,10};
    int dato = 1;
    // se agregan los datos a las dos pilas
    for(int i=0; i<5; i++){
        agregarPila(pila,datos1[i]);
        agregarPila(pila2,datos2[i]);
    }
    for(int i=0; i<5; i++)
    {
        int n = pila2->dato;
        pila2 = pila2->siguiente;

        agregarPila(pila3,n);
        //delete aux;
    }
    // Agrega a la pila3 los elementos de la pila1
    for(int i=0; i<5; i++)
    {
        int n = pila->dato;
        pila = pila->siguiente;
        agregarPila(pila3,n);
        //delete aux;
    }
    // Muestra los elementos de la pila

    cout << "Mostrando los elementos de la pila" <<endl;
    while(pila3 != NULL)
    {
        sacarPila(pila3,dato);

        if(pila3 != NULL)
        {
            cout<<dato<<" , ";
        }
        else
        {
            cout<<dato<<".";
        }
    }
    return 0;
}

void agregarPila(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}
void sacarPila(Nodo *&pila,int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

