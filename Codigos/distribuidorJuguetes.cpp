#include <iostream>
#include <math.h>

using namespace std;

float  A, B, C, D, numJuquetes; // variables para almacenar
// las dimensiones espaciales de la caja y el numero de juguetes a empacar
int numEsferas[4] = {0, 0, 0, 0}; // vector que almacena el numero de esferas

int main()
{
    cout << "Ingrese el numero de juguetes a empacar: ";
    cin >> numJuquetes;
    if(numJuquetes > 0){
        for(int i = 0; i< numJuquetes; i++){
            cout << "Ingrese las dimensiones de la caja #" << i+1 << endl;
            cout << "Ingrese el ancho, largo, alto de la caja separados por espacio: ";
            cin >> A >> B >> C;
            cout << endl;
            D = sqrt(pow(A,2)+pow(B,2)+pow(C,2));
            if(D<=4){
                numEsferas[0]++;
            }
            else if(D>4 && D<=6){
                numEsferas[1]++;
            }
            else if(D>6 && D<=8){
                numEsferas[2]++;
            }
            else if(D>8 && D<10){
                numEsferas[3]++;
            }
            else{
                cout<<"No hay esferas disponibles para el tamano de esa caja" << endl;
            }
        }
        cout << "Numero de cajas de 4in: " << numEsferas[0] << endl;
        cout << "Numero de cajas de 6in: " << numEsferas[1] << endl;
        cout << "Numero de cajas de 8in: " << numEsferas[2] << endl;
        cout << "Numero de cajas de 10in: " << numEsferas[3] << endl;
    }
    else {
        cout << "Debe ingresar un número de cajas mayor que cero";
    }
    return 0;
}
