#include <iostream>
#include <list>
#include <stdlib.h> // para la función rand()
#include <time.h> // para la función time()

using namespace std;
struct listas {
    int numero;
    listas *siguiente;

    listas(int num) {
        numero = num;
        siguiente = NULL;
    }
};

void insertarFinal(int num, listas *&lista){
    listas *nuevo = new listas(num);
    if (lista == NULL){
        lista = nuevo;
    }else{
        listas *aux = lista;
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void llenarListaRandom(int cantidad, list<int> &lista) {
    srand(time(NULL)); // inicializar la semilla para generar números aleatorios
    
    for (int i = 0; i < cantidad; i++) {
        int num = rand(); // generar un número aleatorio
        lista.push_back(num); // agregar el número a la lista
    }
}

int main() {
    list<int> lista;
    llenarListaRandom(10, lista); // llenar la lista con 10 números aleatorios
    for (auto num : lista) {
        cout << num << " "; // imprimir los números de la lista
    }
    cout << endl;
    
    return 0;
}