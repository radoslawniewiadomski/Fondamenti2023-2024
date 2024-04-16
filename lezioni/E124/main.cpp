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

    void stampaFilm();

    // Dichiarazione di funzione amica
    friend bool stessoAnno(const film& f1, const film& f2);
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


// Definizione della funzione amica
bool stessoAnno(const film& f1, const film& f2) {
    return f1._anno == f2._anno;
}

/*
// Funzione per verificare se due film sono stati realizzati nello stesso anno
bool stessoAnno(const film& f1, const film& f2) {
    return f1.getAnno() == f2.getAnno();
}
*/

int main() {
    film film1("Matrix", 120, 2000);
    film film2("Solaris", 90, 1995);
    film film3("Inception", 148, 2010);

    cout << "Film 1 e Film 2 sono stati realizzati nello stesso anno? ";
    if (stessoAnno(film1, film2)) {
        cout << "Sì" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "Film 1 e Film 3 sono stati realizzati nello stesso anno? ";
    if (stessoAnno(film1, film3)) {
        cout << "Sì" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
