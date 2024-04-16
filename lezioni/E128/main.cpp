#include <iostream>
#include <cstring>
using namespace std;

class Film {
    char* titolo;
    int durata;
    int anno;

public:
    // Costruttori
    Film();
    Film(const char* titolo, int durata, int anno);
    // Costruttore di copia
    Film(const Film& otherFilm);
    // Distruttore
    ~Film();

    // Selettori e modificatori
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    //
    void* operator new(size_t size);

    void stampaFilm() const;
};

// Definizioni delle funzioni
Film::Film() {
    titolo = new char[20];
    strcpy(titolo, "N/D");
    durata = 0;
    anno = 0;
}

Film::Film(const char* titolo, int durata, int anno) {
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
    this->durata = durata;
    this->anno = anno;
}

Film::Film(const Film& otherFilm) {
    titolo = new char[strlen(otherFilm.titolo) + 1];
    strcpy(titolo, otherFilm.titolo);
    durata = otherFilm.durata;
    anno = otherFilm.anno;
}

Film::~Film() {
    delete[] titolo;
}

const char* Film::getTitolo() const {
    return titolo;
}

void Film::setTitolo(const char* titolo) {
    delete[] this->titolo;
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
}

int Film::getDurata() const {
    return durata;
}

void Film::setDurata(int durata) {
    this->durata = durata;
}

int Film::getAnno() const {
    return anno;
}

void Film::setAnno(int anno) {
    this->anno = anno;
}

void Film::stampaFilm() const {
    cout << "Titolo: " << titolo << endl;
    cout << "Durata: " << durata << " minuti" << endl;
    cout << "Anno: " << anno << endl;
}


// Definizione dell'overloading di operator new
void* Film::operator new(size_t size) {
    cout << "Allocare memoria per un oggetto Film..." << endl;
    return ::operator new(size);
}



int main() {
    // Creazione di un oggetto Film utilizzando l'overloading di operator new
    Film* filmPtr = new Film("Matrix", 120, 1999);
    filmPtr->stampaFilm();

    // Deallocazione della memoria
    delete filmPtr;

    return 0;
}
