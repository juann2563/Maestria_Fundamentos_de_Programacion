#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

//funciones a utilizar que están declaradas en la part inferior
void pedirDatos(); // pide datos al usuario para llenar la matriz
void mostrarMatriz(float **); // función para poder mostrar la matriz en cualquier momento
void diagonalPrincipal(float **, int, int); // función que pone en 1 la diagonal principal
void gauss(float **, int, int); // Funcion que realzia la descomposición gausiana
// teniendo la descomposicion gaussiana se devuelve para ya tener la descomposición de gauss jordan
void gaussJordan(float **,int,int);
void ultimaColumnaCeros(float **, int);
float **matriz; // matriz dinamica
int nfilas, ncols; //  filas, columnas
float *datos;
float *auxValues; // para los valores de la matriz
int columnaCeros=0;
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
        // calcula la diagonal principal
        if(i==nfilas-1)
        {
            ultimaColumnaCeros(matriz,i);
        }
        // si hay una columna de cero en la última fila no se realzia más proceso
        if(columnaCeros==nfilas){break;}
        diagonalPrincipal(matriz,i,i);
        gauss(matriz,i,i);
    }

    mostrarMatriz(matriz);
    cout << endl << endl;
    //leugo se devuelve para terminar gauss jordan
    if(columnaCeros==nfilas)
    {
        cout << "Soluciones infinitas" << endl;
    }
    else
    {
        for(int i=nfilas-1; i>=0; i--){

            gaussJordan(matriz,i,i);
        }
        mostrarMatriz(matriz);
        cout << endl;
        cout << "Solucion" << endl;
        for(int i=0; i<ncols; i++){
            cout << "x" << i+1 << ": " << datos[i] << endl;
        }
    }

    for(int i=0; i<nfilas; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
    delete[] datos;
    // Se libera la memoria, pero si no se vuelve a asignar algún valor
    // hay una fuga de memoria que hay que volver a ubicar
    matriz = 0;
    datos = 0;
    return 0;
}
void pedirDatos()
{
    cout << "Programa para calcular la solcuion de un sistema de ecuaciones NxN" << endl;
    cout << "Digite el tamano de la matriz NxN: ";
    cin >> nfilas;
    ncols = nfilas;
    datos = new float[nfilas];
    matriz = new float*[nfilas];
    auxValues = new float[nfilas];
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
    cout << "Ingrese el vector solucion" <<endl;
        for(int i=0; i<nfilas; i++){
            cout << "Ingrese el valor "<< i << ": ";
            cin >> datos[i];
            //cout << endl;
        }
    cout << endl;
}
// función para mostrar la matriz
void mostrarMatriz(float **matriz)
{

    for(int i= 0; i<nfilas; i++)
    {
        for(int j=0; j<ncols; j++)
        {

           printf("%.2f ",matriz[i][j]);
        }
        printf(" | ");
        printf("%.2f ",datos[i]);
        cout << endl;
    }
}
//funcion para poner en la diagonal principal los unos necesario para gauss jordan
void diagonalPrincipal(float **matriz, int fila, int col){
    float x; // para poner uno en la diagonal principal
    x = matriz[fila][col];
    int auxFila =fila; // para saber en que fila está actualmente
    float auxValVecSol=0; // vector auxiliar para poder inercambair las posiciones del vector auxiliar
    int cont = 1;
    // si la posicion donde va a estar el pivote es cero se deben intercambiar filas hasta que no sea cero
    if(x == 0 && fila<nfilas-1)
    {
        while(true){
            cout << "f" << fila << " <--> " << "f" << cont <<endl;
            for(int i= 0; i<nfilas; i++)
            {
                //Intercambia las columnas de la matriz
                auxValues[i] = matriz[fila][i];
                matriz[fila][i] = matriz[auxFila+1][i];
                matriz[auxFila+1][i] = auxValues[i];
                //intercambia las posiciones del vector solucion
                auxValVecSol = datos[fila];
                datos[fila] = datos[auxFila+1];
                datos[auxFila+1] = auxValVecSol;
            }
            //muestra el estado de la matriz
            mostrarMatriz(matriz);
            // si ya hay un valor difefernete de uno de los valores de la diagonal pricipal sale del ciclo
            if(matriz[fila][col] != 0){
                break;
            }
            // aumenta el contador a la fila sigiente para seguir buscando si hay una fila con valor diferente de cero
            auxFila++;
            // si el contador llega al numero de filas no realiza nada más porque ya no hay más filas disponibles
            if(auxFila == nfilas){
                cout << "No tiene solucion" << endl;
            }
        }
    }
    //No realiza nada si el valor actual de la diagonal es 1
    else if(x == 1){}
    else
    {
        cout << "f" << fila << " dividido " << x << endl;
        for(int i=col; i<ncols; i++)
        {
            matriz[fila][i]=(matriz[fila][i])/x;

        }
        datos[fila]=datos[fila]/x;
        mostrarMatriz(matriz);
        cout << endl;

    }
}
// función para realziar gauss
void gauss(float **matriz, int fila, int col)
{
    //inicia en la filaActual + 1 para poder ser restada con la fila actual
    for(int i=fila+1; i<nfilas; i++)
    {
        //obtiene el valor de la fila actual y la fila +1
        float valCero1 = matriz[i][fila];
        float valCero2 = matriz[fila][col];
        if(valCero1 ==0 || valCero2==0){}
        else
        {
            cout <<"f" << i << " menos " << valCero1 << "/" << valCero2 <<" f" << fila <<endl;
            //cout << valCero2 << "f" << i << " menos " << valCero1 << "f" << fila <<endl;
            for(int j=col; j<ncols; j++)
            {
                //multiplica cada valor de la fila por el valor que lo hace cero
                matriz[i][j] = matriz[i][j] - (valCero1/valCero2)*matriz[fila][j];
                //matriz[i][j] = matriz[i][j]*valCero2 - valCero1*matriz[fila][j];

            }
            // para operar el vector solucion
            datos[i] = datos[i]*valCero2 - valCero1*datos[fila];
            //muestra el stado de la matriz
            mostrarMatriz(matriz);
            cout << endl;

        }
    }
}
//Funcion para completar gauss jordan
void gaussJordan(float **matriz,int fila, int col)
{
    for(int i=fila-1; i>=0; i--)
    {
        float valCero1 = matriz[i][fila];
        float valCero2 = matriz[fila][col];
        if(valCero1 ==0 || valCero2==0){}
        else
        {
            cout << valCero2 << "f" << i << " menos " << valCero1 << "f" << fila <<endl;
            for(int j=col; j>=0; j--)
            {

                matriz[i][j] = matriz[i][j]*valCero2 - valCero1*matriz[fila][j];

            }
            datos[i] = datos[i]*valCero2 - valCero1*datos[fila];
            mostrarMatriz(matriz);
            cout << endl;

        }

    }
}
// Si la última columna es de ceros no sigue más
void ultimaColumnaCeros(float **matriz, int fila){

    for(int i=fila; i<nfilas;i++){
        for(int j=0; j<ncols; j++)
        {
            if(matriz[fila][j]==0){
                columnaCeros++;
            }
        }
    }
}
