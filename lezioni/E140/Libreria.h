#include "Libro.h"

class Libreria {
    int id;
    Libro* libri;
    int numLibri;

public:
    // Costruttore
    Libreria(int id);

    // Distruttore
    ~Libreria();

    // Metodo per inserire un libro nella libreria
    void inserisciLibro(const Libro& libro);

    // Metodo per ottenere il numero di libri nella libreria
    int getNumLibri() const;
};
