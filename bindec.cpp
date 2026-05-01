#include <iostream>
#include <string>
using namespace std;

int main() {
    string binario;
    int decimal = 0;
    int potencia = 1;
    
    cout << "Ingrese un numero binario: ";
    cin >> binario;
    
    for (int i = binario.length() - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += potencia;
        }
        potencia *= 2;
    }
    
    cout << "El numero decimal es: " << decimal << endl;
    
    return 0;
}