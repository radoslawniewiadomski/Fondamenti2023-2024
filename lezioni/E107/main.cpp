#include <iostream>
#include <cstring>
using namespace std;

class film {
    char* _titolo;
    int _durata;
    int _anno;

public:
    // Costruttori
    film();
    film(char* titolo, int durata, int anno);
    // Costruttore di copia
    film(const film& otherFilm);
    // Distruttore
    ~film();

    // Selettori e modificatori
    char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    // Operatore -
    film operator!();

    void stampaFilm();
};

// Definizioni delle funzioni
film::film() {
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

film::film(char* titolo, int durata, int anno) {
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
}

film::film(const film& otherFilm) {
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;
}

film::~film() {
    delete[] _titolo;
}

char* film::getTitolo() const {
    return _titolo;
}

void film::setTitolo(const char* titolo) {
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

int film::getDurata() const {
    return _durata;
}

void film::setDurata(int durata) {
    _durata = durata;
}

int film::getAnno() const {
    return _anno;
}

void film::setAnno(int anno) {
    _anno = anno;
}

void film::stampaFilm() {
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout << "Anno: " << _anno << endl;
}

// Implementazione dell'operatore -
film film::operator!()  {
    char* invertedTitolo = new char[strlen(_titolo) + 1];
    int length = strlen(_titolo);
    for (int i = 0; i < length; ++i) {
        invertedTitolo[i] = _titolo[length - 1 - i];
    }
    invertedTitolo[length] = '\0';

    film invertedFilm(invertedTitolo, _durata, _anno);
    delete[] invertedTitolo;

    return invertedFilm;
}

    int main() {
        film mioFilm("Inception", 148, 2010);
        mioFilm.stampaFilm();

        film filmInvertito = !mioFilm;
        cout << "Titolo invertito: " << filmInvertito.getTitolo() << endl;

        return 0;
    }
