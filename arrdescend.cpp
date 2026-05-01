#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Ingrese un numero positivo: ";
    cin >> n;
    
    int arr[100];
    
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
    
    cout << "Arreglo descendente: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}