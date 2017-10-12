#include <iostream>

using namespace std;
float m1[2][3] = {{400,200,50},{300,100,30}};
float m2[3][2] = {{25, 1},{30,1.2},{33,1.3}};
float m3[2][2] = {{0,0},{0,0}};
void calculo(int filas, int col);
void mostrar();
int main()
{
    cout << "Producción de lavadoras " << endl;
    cout << "\t      N   L   S" << endl;
    cout << "Modelo A --> ";
    for(int i=0; i<2; i++){

        for(int j=0; j<3; j++){
            cout << m1[i][j] << " ";
        }
        if(i==1){break;}
         cout <<endl;
        cout << "Modelo B --> ";

    }
    cout << endl;
    cout << "\thoras admin" << endl;
    cout << "N --> ";
    for(int i=0; i<3; i++){
        if(i==1){
            cout <<endl;
            cout << "N --> ";
        }
        if(i==2){
            cout <<endl;
            cout << "L --> ";
        }
        for(int j=0; j<2; j++){
//
            cout << "   " << m2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    calculo(2,3);
    mostrar();
    return 0;
}
void calculo(int filas,int col)
{
    float temporal;
    for(int i=0;i<filas;i++)
    {
        for(int k=0;k<filas;k++)
        {
            temporal=0;
            for(int j=0;j<col;j++)
            {
                temporal+=m1[i][j]*m2[j][k];
                m3[i][k]=temporal;
            }
        }
    }
}

void mostrar(){
    cout << "taller admin" << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
}

