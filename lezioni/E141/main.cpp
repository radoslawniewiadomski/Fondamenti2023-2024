#include "Film.h"
#include <iostream>
using namespace std;


int main() {
    int lunghezzaTitolo;
    cout << "Inserisci la lunghezza del titolo del film: ";
    cin >> lunghezzaTitolo;

    // Allocazione dinamica della memoria per il titolo del film
    char* titolo = new char[lunghezzaTitolo + 1];

    cout << "Inserisci il titolo del film (mass. " << lunghezzaTitolo << " caratteri): ";
    cin >> titolo;

    int durata, anno;
    cout << "Inserisci durata: ";
    cin >> durata;
    cout << "Inserisci anno: ";
    cin >> anno;

    film p(titolo, durata, anno);
    p.stampaFilm();

    delete[] titolo;
    return 0;
}

