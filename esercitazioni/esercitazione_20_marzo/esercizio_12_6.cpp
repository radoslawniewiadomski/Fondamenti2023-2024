#include <iostream>
using namespace std;

// Definizione di una funzione template per la somma di due numeri
template<typename T>
T sum(T a, T b) {
    return a + b;
}

// Definizione di una funzione template per il prodotto di due numeri
template<typename T>
T product(T a, T b) {
    return a * b;
}

// Funzione per eseguire un'operazione specificata su due numeri usando un puntatore a funzione
template<typename T>
T executeOperation(T a, T b, T(*operation)(T, T)) {
    return operation(a, b);
}

int main() {
    int x = 5, y = 3;

    // Definizione di un puntatore a funzione per la somma
    int(*sumPtr)(int, int) = sum;

    // Esecuzione dell'operazione di somma tramite il puntatore a funzione
    cout << "Sum: " << executeOperation(x, y, sumPtr) << endl;

    // Definizione di un puntatore a funzione per il prodotto
    int(*productPtr)(int, int) = product;

    // Esecuzione dell'operazione di prodotto tramite il puntatore a funzione
    cout << "Product: " << executeOperation(x, y, productPtr) << endl;


     float x2 = 5.2, y2 = 3.3;

    // Definizione di un puntatore a funzione per la somma
    float(*sumPtr2)(float, float) = sum;

    // Esecuzione dell'operazione di somma tramite il puntatore a funzione
    cout << "Sum: " << executeOperation(x2, y2, sumPtr2) << endl;

    // Definizione di un puntatore a funzione per il prodotto
    float(*productPtr2)(float, float) = product;

    // Esecuzione dell'operazione di prodotto tramite il puntatore a funzione
    cout << "Product: " << executeOperation(x2, y2, productPtr2) << endl;


    return 0;
}
