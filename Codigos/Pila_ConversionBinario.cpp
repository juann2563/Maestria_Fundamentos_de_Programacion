#include <iostream>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};

typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )

/*                        Apilar elemento
------------------------------------------------------------------------*/
void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;

     aux->sgte = p ;
     p = aux ;
}



/*                     Muestra elementos de la pila
------------------------------------------------------------------------*/
void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista

     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro << " ";
            aux = aux->sgte;
     }
}

/*                Eliminar todos los elementos de la pila
------------------------------------------------------------------------*/

int binario[50]; //almacenar binario
int a,b, num;
void conversion_binario(int num)
{

    for(b=0;b<50; ++b)
    {
        binario[b] = num%2;
        num=num/2;
        if(num==0){
            break;
        }
    }
}

int main()
{
    ptrPila p = NULL;  // creando pila
    ptrPila p2 = NULL;
    int dato;
    cout<< "\n NUMERO A convertir a binario: ";
    cin>> dato;
    conversion_binario(dato);
    for(a=b;a>=0;--a){
        push(p,binario[a]);
        //cout << binario[a];
    }
    for(a=b;a>=0;--a){
        push(p2,p->nro);
        p = p->sgte;
        //cout << binario[a];
    }
    cout << endl;
    mostrar_pila(p2);
    cout << endl;
    return 0;
}
