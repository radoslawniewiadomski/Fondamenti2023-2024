#include "Libro.h"

// Definizioni dei metodi della classe Libro
Libro::Libro() : anno(0) {
    autore[0] = '\0';
    titolo[0] = '\0';
}

Libro::Libro(const char* autore, const char* titolo, int anno) : anno(anno) {
    strncpy(this->autore, autore, 20 - 1);
    this->autore[19] = '\0';
    strncpy(this->titolo, titolo, 20 - 1);
    this->titolo[19] = '\0';
}

const char* Libro::getAutore() const {
    return autore;
}

const char* Libro::getTitolo() const {
    return titolo;
}

int Libro::getAnno() const {
    return anno;
}
