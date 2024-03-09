#include <iostream>
using namespace std;

void leggi_vettore(int vettore[], int dimensione) {
    cout << "Inserisci " << dimensione << " elementi nel vettore:" << endl;
    for (int i = 0; i < dimensione; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vettore[i];
    }
}

void stampa_vettore( int vettore[], int dimensione) {
    cout << "Elementi del vettore:" << endl;
    for (int i = 0; i < dimensione; ++i)  cout << vettore[i] << ", ";
    cout << endl;
}


void somma_vettore(int vettore[], int dimensione) {
    int somma = 0;
    for (int i = 0; i < dimensione; ++i)
        somma += vettore[i];
    cout << "Somma degli elementi del vettore: " << somma << endl;
}

int main() {
    // Dimensione del vettore
    const int DIMENSIONE = 5;
    int vettore[DIMENSIONE];

    // Array di puntatori a funzione
    void (*funzioni[3])(int[], int) = {leggi_vettore, stampa_vettore, somma_vettore};

    for (int i = 0; i < 3; ++i)  (*funzioni[i ])(vettore, DIMENSIONE);
    return 0;
}
