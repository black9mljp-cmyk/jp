#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cantidad;
    
    cout << "Ingrese la cantidad de numeros: ";
    cin >> cantidad;
    
    vector<int> numeros(cantidad);
    vector<int> inversos(cantidad);
    
    cout << "Ingrese los numeros:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    
    for (int i = 0; i < cantidad; i++) {
        inversos[i] = -numeros[i];
    }
    
    cout << "\nNumeros originales: ";
    for (int i = 0; i < cantidad; i++) {
        cout << numeros[i] << " ";
    }
    
    cout << "\nInversos aditivos: ";
    for (int i = 0; i < cantidad; i++) {
        cout << inversos[i] << " ";
    }
    cout << endl;
    
    return 0;
}