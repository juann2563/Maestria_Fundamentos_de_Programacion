#include <iostream>

using namespace std;
int N, M, cont=0, promedio=0;
float cantPrimos;
int main()
{
    cout << "Programa para generar numeros primos entre un rango específico" << endl;
    cout << "Los rangos deben numeros mayores que cero" << endl;
    // PRegunta al usuario hasta que ingrese correctamente los datos
    do{
        cout << "Ingrese el rango inferior y superior separados por espacio: ";
        cin >> N >> M;
        // Se verifica que sean enteros positivos
        if(N==0 || M==0){
            cout << "Los rangos deben ser mayores que cero" << endl;
        }
        // verifica que el rango superior sea mayor que el inferior
        if(M<=N){
            cout << "El rango superior debe ser mayor que el inferior" << endl;
        }
    }while(N<=0 || M<=0 || M<=N);

    cout << "Numeros primos: ";
    for(int i = N; i<=M; i++) // rangos para los numeros primos
    {
        for(int j=1; j<=i; j++)
        {
            // se va verificando si el número actual es primo con los primos an teriores a el
            // y si el modulo es cero aumenta el contador
            if(i%j==0)
            {
                cont++; // se cuenta cada vez que el modulo es cero
            }
        }
        // Para que sea primo debe ser solo dividido por el mismo y por 1
        // osea que cont solo puede valer dos para que sea primo de lo contrario no es primo
        if(cont == 2)
        {
            cont = 0;
            cantPrimos++;
            promedio = promedio + i;
            cout << i << " ";
        }
        // se resetea cont para evitar que siga contando
        else {
            cont = 0;
        }
    }
    cout << "\nCantidad de numeros primos: " << cantPrimos << endl;
    cout << "Promedio: " << promedio/cantPrimos << endl;
    return 0;
}
