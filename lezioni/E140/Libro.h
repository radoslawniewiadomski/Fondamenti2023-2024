
#include <iostream>
#include <cstring>
#ifndef LIBRO_H
#define LIBRO_H


using namespace std;

class Libro {
    char autore[20];
    char titolo[20];
    int anno;

public:
    // Costruttori
    Libro();
    Libro(const char* autore, const char* titolo, int anno);

    // Metodi di accesso
    const char* getAutore() const;
    const char* getTitolo() const;
    int getAnno() const;
};

#endif // LIBRO_H
