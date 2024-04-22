#include "Libreria.h"
#include "Libro.h"

// Definizioni dei metodi della classe Libreria
Libreria::Libreria(int id) : id(id), numLibri(0), libri(nullptr) {}

Libreria::~Libreria() {
    delete[] libri;
}

void Libreria::inserisciLibro(const Libro& libro) {
    Libro* temp = new Libro[numLibri + 1];

    for (int i = 0; i < numLibri; ++i) {
        temp[i] = libri[i];
    }

    temp[numLibri] = libro;

    delete[] libri;
    libri = temp;
    numLibri++;
}

int Libreria::getNumLibri() const {
    return numLibri;
}
