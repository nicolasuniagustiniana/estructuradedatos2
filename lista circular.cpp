#include <iostream>

// Definición de la estructura del nodo
struct Nodo {
    int valor;
    Nodo* siguiente;
    
    Nodo(int val) : valor(val), siguiente(NULL) {}
};

// Clase para la lista circular
class ListaCircular {
private:
    Nodo* cabeza;
    
public:
    ListaCircular() : cabeza(NULL) {}
    
   
    void agregarAlFinal(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza; // Hacer que el único nodo apunte a sí mismo
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza; // Hacer que el nuevo nodo apunte a la cabeza
        }
    }
    
    void imprimir() {
        if (!cabeza) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }
        
        Nodo* temp = cabeza;
        do {
            std::cout << temp->valor << " ";
            temp = temp->siguiente;
        } while (temp != cabeza);
        
        std::cout << std::endl;
    }
    
    ~ListaCircular() {
        if (!cabeza) return;
        
        Nodo* actual = cabeza;
        Nodo* siguiente = cabeza->siguiente;
        
        while (siguiente != cabeza) {
            delete actual;
            actual = siguiente;
            siguiente = siguiente->siguiente;
        }
        
        delete actual; // Eliminar el último nodo
    }
};

int main() {
    ListaCircular lista;
    lista.agregarAlFinal(4);
    lista.agregarAlFinal(5);
    lista.agregarAlFinal(6);
    lista.agregarAlFinal(8);

    std::cout << "Lista circular: ";
    lista.imprimir();

    return 0;
}
