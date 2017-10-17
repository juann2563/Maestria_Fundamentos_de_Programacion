#include <iostream>
#include <string>

using namespace std;

void binario(int n){
    if(n>1){
        binario(n/2);
    }
    cout << n%2;
}
void octal(int n){
    if(n>8){
        octal(n/8);
    }
    cout << n%8;
}
void hexadecimal(int value)
{
    if (value == 0){
        return;
    }

    int rem = value % 16;
    value /= 16;
    hexadecimal(value);


    if (rem > 9)
        cout << (char)(rem - 10 + 'A');
    else
        cout << rem;
}

char letra;
int numero;
int main()
{
    cout << "Ingrese 'b' para binario, 'o' para octal, 'h' para hexadecimal : ";
    cin >> letra;
    if(letra=='b'){
        cout << "Ingrese un numero decimal: ";
        cin >> numero;
        binario(numero);
        cout << endl;
    }
    if(letra=='o'){
        cout << "Ingrese un numero decimal: ";
        cin >> numero;
        cout << "Octal: ";
        octal(numero);
    }
    if(letra=='h'){
        cout << "Ingrese un numero decimal: ";
        cin >> numero;
        hexadecimal(numero);
        //cout << 123/16 << 123%16;
    }
    cout << endl;
    return 0;
}
