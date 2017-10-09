#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void pedirDatos(); // pide datos al usuario para llenar la matriz
void mostrarMatriz(float **); // función para poder mostrar la matriz en cualquier momento
void diagonalPrincipal(float **, int, int); // función que pone en 1 la diagonal principal
void gauss(float **, int, int); // Funcion que realzia la descomposición gausiana
void gaussJordan(float **,int,int);
void intercambiarFilas(float **, int, int);
float **matriz; // matriz dinamica
int nfilas, ncols; //  filas, columnas
float det = 1;
float *auxValues; // para los valores de la matriz
using namespace std;
int main()
{
    /*1 - pedir datos a usuario
      2- Calcular diagonal principal
      3 - calcular gauss
      4 - devolverse con el resultado de gauss para terminar gauss-jordan
        (Ya no es necesario calcular la diagonal principal)*/

    pedirDatos();
    cout << "Matriz" << endl;
    mostrarMatriz(matriz); //muestra la matriz ingresada
    cout << endl;
    // realiza primero gauss
    for (int i=0; i<nfilas; i++){
            if(matriz[i][i]==0){
                intercambiarFilas(matriz,i,i);
            }
        // calcula la diagonal principal
        //diagonalPrincipal(matriz,i,i);
        gauss(matriz,i,i);
    }
    //calcular determinante
    // multiplica toda la diagonal principal
    for(int i=0; i<nfilas; i++){
        for(int j=0; j<ncols; j++){
            if(i==j){
                det=det*matriz[i][j];
            }
        }
    }

    mostrarMatriz(matriz);
    cout << "El determinante es la multiplicacion de la diagonal principal" << endl;
    cout << "por cada cambio de fila el determinante se multiplica por -1" << endl << endl;
    cout << "determinante= " << det << endl;

    for(int i=0; i<nfilas; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
    // Se libera la memoria, pero si no se vuelve a asignar algún valor
    // hay una fuga de memoria que hay que volver a ubicar
    matriz = 0;
    delete[] auxValues;
    auxValues =0;
    return 0;
}
void pedirDatos()
{
    cout << "Digite el tamano de la matriz NxN: ";
    cin >> nfilas;
    ncols = nfilas;
    matriz = new float*[nfilas]; // crea matriz dinamica
    auxValues = new float[nfilas]; // vector dinamico
    for (int i=0; i<nfilas; i++)
    {
        matriz[i]= new float(ncols); // reservando memeoria para las columnas
    }
    cout << "digitando los elementos de la matriz" << endl;
    for(int i=0; i<nfilas; i++)
    {
        for(int j=0; j<ncols; j++)
        {
            cout << "Ingrese un numero en la posicion [" << i << "," << j <<"]: ";
            cin >> matriz[i][j]; // es lo mismo matriz[i][j];
        }
    }
    cout << endl;
}
//funcion para mostrar matriz
void mostrarMatriz(float **matriz)
{

    for(int i= 0; i<nfilas; i++)
    {
        for(int j=0; j<ncols; j++)
        {

           printf("%.2f ",matriz[i][j]);
        }
        cout << endl;
    }
}
// funcion para calcular gauss
void gauss(float **matriz, int fila, int col)
{

    for(int i=fila+1; i<nfilas; i++)
    {

        float valCero1 = matriz[i][col];
        float valCero2 = matriz[fila][col];
        if(valCero1 ==0 || valCero2==0){}
        else
        {
            cout <<"f" << i << " menos " << valCero1 << "/" << valCero2 <<" f" << fila <<endl;
            for(int j=col; j<ncols; j++)
            {

                matriz[i][j] = matriz[i][j] - (valCero1/valCero2)*matriz[fila][j];

            }

            mostrarMatriz(matriz);
            cout << endl;

        }
    }
}

void intercambiarFilas(float **matriz,int fila, int col){
    int cont=1;
    int auxFila =fila;
    while(true){
        det = det*-1;
        cout << "f" << fila << " <--> " << "f" << cont <<endl;
        for(int i= 0; i<nfilas; i++)
        {
            //Intercambia las columnas de la matriz
            auxValues[i] = matriz[fila][i];
            matriz[fila][i] = matriz[auxFila+1][i];
            matriz[auxFila+1][i] = auxValues[i];
            //intercambia las posiciones del vector solucion
        }

        //cout << "Determinante: "<<det <<endl;
        mostrarMatriz(matriz);
        // Si ya encontró el la fila con el valor diferente de cero no tiene que seguir hacidno más
        if(matriz[fila][col] != 0)
        {
            break;
        }
        auxFila++;
        if(auxFila == nfilas){
            cout << "No tiene solucion" << endl;
            break;
        }
    }
    cout << endl;
}
