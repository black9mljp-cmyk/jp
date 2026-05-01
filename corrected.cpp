#include <iostream>
using namespace std;

int addFive(int num);
int main() {
    int numero;
    
    cin >> numero;
    
    cout << addFive(numero) << endl;
    
    return 0;
}

//para que la funcion addFive funciona esta necesita hacer la suma junto al comando return, ya que si se hace la suma antes del return, el resultado no se va a mostrar en pantalla
int addFive(int num) {
    return num + 5;
}
