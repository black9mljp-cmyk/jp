#include <iostream>
#include <string>
using namespace std;

string invertirCadena(string cadena, int a, int b) {
    // Ajustar b si es mayor que la longitud de la cadena
    int longitud = cadena.length();
    if (b >= longitud) {
        b = longitud - 1;
    }
    
    // Validar que a y b sean válidos
    if (a < 0) a = 0;
    if (a > b) return cadena;
    
    // Invertir la parte entre a y b (inclusive)
    while (a < b) {
        swap(cadena[a], cadena[b]);
        a++;
        b--;
    }
    
    return cadena;
}

int main() {
    string texto = "Hola Mundo";
    int a = 2;
    int b = 8;
    
    cout << "Cadena original: " << texto << endl;
    cout << "Cadena invertida (" << a << " a " << b << "): " << invertirCadena(texto, a, b) << endl;
    
    return 0;
}