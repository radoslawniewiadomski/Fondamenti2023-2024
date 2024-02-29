#include <iostream>
using namespace std;

// Funzione per calcolare il prodotto scalare di due array
float prodotto_scalare(const float *px, const float *py, int n) {
    float risultato = 0.0;
    for (int i = 0; i < n; ++i) {
        risultato += (*(px + i)) * (*(py + i));
    }
    return risultato;
}

int main() {
    const int dimensione = 5; // Dimensione comune dei due array

    // Dichiarazione e allocazione di memoria per gli array
    float array_x[dimensione];
    float array_y[dimensione];

    // Input degli elementi del primo array
    cout << "Inserisci gli elementi del primo array:" << endl;
    for (int i = 0; i < dimensione; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array_x[i];
    }

    // Input degli elementi del secondo array
    cout << "Inserisci gli elementi del secondo array:" << endl;
    for (int i = 0; i < dimensione; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array_y[i];
    }

    // Calcola e stampa il prodotto scalare
    float risultato = prodotto_scalare(array_x, array_y, dimensione);
    cout << "Il prodotto scalare degli array è: " << risultato << endl;

    return 0;
}
