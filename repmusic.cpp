#include <iostream>
#include <string>
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
using namespace std;

struct Cancion {
    string nombre;
    string artista;
    string duracion;
    Cancion* siguiente;
    Cancion* anterior;
};

Cancion* cabeza = nullptr;
int total = 0;

void agregarCancion() {
    Cancion* nueva = new Cancion();
    cout << "\nNombre de la cancion: ";
    cin.ignore();
    getline(cin, nueva->nombre);
    cout << "Artista: ";
    getline(cin, nueva->artista);
    cout << "Duracion (ej. 3:45): ";
    getline(cin, nueva->duracion);

    if (cabeza == nullptr) {
        nueva->siguiente = nueva;
        nueva->anterior = nueva;
        cabeza = nueva;
    } else {
        Cancion* ultimo = cabeza->anterior;
        ultimo->siguiente = nueva;
        nueva->anterior = ultimo;
        nueva->siguiente = cabeza;
        cabeza->anterior = nueva;
    }
    total++;
    cout << "\nCancion agregada!\n";
}

void mostrarLista() {
    if (cabeza == nullptr) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }
    cout << "\n===== LISTA DE CANCIONES =====\n";
    Cancion* actual = cabeza;
    int i = 1;
    do {
        cout << i++ << ". " << actual->nombre << " - " << actual->artista
             << " [" << actual->duracion << "]\n";
        actual = actual->siguiente;
    } while (actual != cabeza);
    cout << "==============================\n";
}

int leerTecla() {
#if defined(_WIN32) || defined(_WIN64)
    int ch = _getch();
    if (ch == 27) return 0; 
    if (ch == 224) { 
        int ch2 = _getch();
        if (ch2 == 77) return 1; 
        if (ch2 == 75) return 2; 
    }
    return -1;
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int ch = getchar();
    if (ch == 27) { 
        int ch2 = getchar();
        if (ch2 == '[') {
            int ch3 = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            if (ch3 == 'C') return 1;  
            if (ch3 == 'D') return 2;  
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return 0; 
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return -1;
#endif
}

void mostrarCancionActual(Cancion* c, int pos) {
    cout << "\n========== REPRODUCIENDO ==========\n";
    cout << "  [" << pos << "/" << total << "] " << c->nombre << "\n";
    cout << "  Artista  : " << c->artista << "\n";
    cout << "  Duracion : " << c->duracion << "\n";
    cout << "====================================\n";
    cout << "  <- Anterior  |  Siguiente ->  |  ESC Salir\n";
}

void reproducirPlaylist() {
    if (cabeza == nullptr) {
        cout << "\nNo hay canciones en la lista.\n";
        return;
    }

    Cancion* actual = cabeza;
    int pos = 1;

    mostrarCancionActual(actual, pos);

    while (true) {
        int tecla = leerTecla();
        if (tecla == 0) break; 
        else if (tecla == 1) { 
            actual = actual->siguiente;
            pos = (pos % total) + 1;
            mostrarCancionActual(actual, pos);
        } else if (tecla == 2) { 
            actual = actual->anterior;
            pos = (pos - 2 + total) % total + 1;
            mostrarCancionActual(actual, pos);
        }
    }
    cout << "\nRegresando al menu...\n";
}

int main() {
    int opcion;
    do {
        cout << "\n====== REPRODUCTOR DE MUSICA ======\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar lista completa\n";
        cout << "3. Reproducir playlist\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarCancion(); break;
            case 2: mostrarLista(); break;
            case 3: reproducirPlaylist(); break;
            case 4: cout << "Hasta luego!\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}