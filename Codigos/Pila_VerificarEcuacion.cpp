/*Ejercicio 1: Hacer un programa para agregar números enteros a una pila, hasta que el
usuario lo decida, después mostrar todos los números introducidos en la pila.*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipos de Función
void agregarPila(Nodo *&,char);
void sacarPila(Nodo *&,char &);

int main(){
    Nodo *pila = NULL;	//Inicializamos pila
    char dato;
    Nodo *pila2 = NULL;
    string rpt;
    int parentesis1=0, parentesis2=0, llaves1=0, llaves2=0, corchetes1=0, corchetes2=0;
    cout << "Ingrese la ecuacion sin dejar espacios entre numeros y corchetes, llaves, parentesis" << endl;
    cout << "Por ejemplo [(5+6)*10/(1/8)]" <<endl;
    cout << "Ingrese la ecuacion: ";
    cin >> rpt;
    cout << rpt << endl;
    for(int i=0; i<rpt.length(); i++){
        agregarPila(pila,rpt[i]);
    }
    for(int i=0; i<rpt.length(); i++){
        agregarPila(pila2,pila->dato);
        pila = pila->siguiente;
    }

    for(int i=0; i<rpt.length(); i++){
        if(rpt[i]=='('){
            parentesis1++;
        }
        if(rpt[i]==')'){
            parentesis2++;
        }
        if(rpt[i]=='{'){
            llaves1++;
        }
        if(rpt[i]=='}'){
            llaves2++;
        }
        if(rpt[i]=='['){
            corchetes1++;
        }
        if(rpt[i]==']'){
            corchetes2++;
        }
    }
    cout << endl;
    if(corchetes1 != corchetes2){
        cout << "Corchetes Desvalanceados" << endl;
    }
    if(parentesis1 != parentesis2){
        cout << "Parentesis Desvalanceados" << endl;
    }
    if(llaves1 != llaves2){
        cout << "Llaves desvalanceadas" << endl;
    }

    cout<<"\nMostrando los elementos de la pila: ";
    while(pila2 != NULL){
        sacarPila(pila2,dato);

        if(pila2 != NULL){
            cout<<dato<<" ";
        }
        else{
            cout<<dato<<" ";
        }
    }

    getch();
    return 0;
}

void agregarPila(Nodo *&pila,char n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    //cout<<"\tElemento "<<n<<" agregado a PILA correctamente";
}

void sacarPila(Nodo *&pila,char &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}
