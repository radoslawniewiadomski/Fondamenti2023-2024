#include "Libreria.h"
#include <iostream>

using namespace std;


int main() {
    int numLibri;

    cout << "Quanti libri contiene la libreria? ";
    cin >> numLibri;

    Libreria libreria(1); // Creiamo una libreria con ID 1

    for (int i = 0; i < numLibri; ++i) {
        char autore[20];
        char titolo[20];
        int anno;

        cout << "Inserisci autore del libro " << i + 1 << ": ";
        cin >> autore;

        cout << "Inserisci titolo del libro " << i + 1 << ": ";
        cin >> titolo;

        cout << "Inserisci anno di stampa del libro " << i + 1 << ": ";
        cin >> anno;

        Libro libro(autore, titolo, anno);
        libreria.inserisciLibro(libro);
    }

    cout << "La libreria contiene " << libreria.getNumLibri() << " libri." << endl;

    return 0;
}
