#include <iostream>

struct Nodo {
    int valor;
    Nodo* anterior;
    Nodo* siguiente;
    
    Nodo(int val) : valor(val), anterior(NULL), siguiente(NULL) {}
};

class ListaDobleEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;
    
public:
    ListaDobleEnlazada() : cabeza(NULL), cola(NULL) {}
    
    void agregarAlFinal(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }
    
    void imprimirAdelante() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
    
    // Método para imprimir la lista desde la cola hacia la cabeza
    void imprimirAtras() {
        Nodo* actual = cola;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->anterior;
        }
        std::cout << std::endl;
    }
    
    // Destructor para liberar la memoria
    ~ListaDobleEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaDobleEnlazada lista;
    lista.agregarAlFinal(8);
    lista.agregarAlFinal(9);
    lista.agregarAlFinal(10);
    lista.agregarAlFinal(12);

    std::cout << "Lista desde adelante: ";
    lista.imprimirAdelante();

    std::cout << "Lista desde atrás: ";
    lista.imprimirAtras();

    return 0;
}