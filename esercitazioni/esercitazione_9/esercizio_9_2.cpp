#include <iostream>

using namespace std;

// Funzione per trovare il puntatore al massimo tra tre numeri
int* massimo(int* a, int* b, int* c) {
    if (*a >= *b && *a >= *c) {
        return a;
    } else if (*b >= *a && *b >= *c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int num1, num2, num3;

    // Input dei tre numeri interi
    cout << "Inserisci tre numeri interi:" << endl;
    cout << "Numero 1: ";
    cin >> num1;
    cout << "Numero 2: ";
    cin >> num2;
    cout << "Numero 3: ";
    cin >> num3;

    // Chiamata alla funzione massimo
    int* max_ptr = massimo(&num1, &num2, &num3);

    // Stampa il valore puntato dal puntatore restituito dalla funzione
    cout << "Il numero massimo tra " << num1 << ", " << num2 << " e " << num3 << " è: " << *max_ptr << endl;

    return 0;
}
