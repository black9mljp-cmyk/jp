#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};

void agregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void mostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "  (La lista está vacía)" << endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "  [" << actual->dato << " | ";
        if (actual->siguiente != nullptr) {
            cout << "*]   ";
        } else {
            cout << "NULL]";
        }
        actual = actual->siguiente;
    }
    cout << endl;
}

void liberarMemoria(Nodo*& cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza = nullptr;
}

int main() {
    Nodo* cabeza = nullptr;
    char respuesta;
    int valor;
    cout << "LISTA ENLAZADA DINAMICA" << endl;
    do {
        cout << "\nDesea ingresar un nuevo valor? (S/N): ";
        cin >> respuesta;
        respuesta = toupper(respuesta);

        if (respuesta == 'S') {
            cout << "Ingrese el valor entero: ";
            cin >> valor;
            agregarNodo(cabeza, valor);
            cout << "Nodo agregado correctamente." << endl;
        } else if (respuesta != 'N') {
            cout << "Opcion no valida. Ingrese S o N." << endl;
        }

    } while (respuesta != 'N');

    cout << "\nContenido de la lista:\n" << endl;
    mostrarLista(cabeza);

    liberarMemoria(cabeza);
    cout << "\nMemoria liberada correctamente." << endl;
    cout << "======================================\n" << endl;

    return 0;
}