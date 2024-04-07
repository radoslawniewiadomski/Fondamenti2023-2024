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

film* creaSequel(const film* f, int anno) {
    char* nuovoTitolo = new char[strlen(f->getTitolo()) + 3];
    strcpy(nuovoTitolo, f->getTitolo());
    strcat(nuovoTitolo, " 2");

    film *nuovo = new film(nuovoTitolo, f->getDurata(), anno);
    delete[] nuovoTitolo;
    return nuovo;
}


int main() {
    int lunghezzaTitolo;
    cout << "Inserisci la lunghezza del titolo del film: ";
    cin >> lunghezzaTitolo;

    // Allocazione dinamica della memoria per il titolo del film
    char* titoloInput = new char[lunghezzaTitolo + 1];

    cout << "Inserisci il titolo del film (massimo " << lunghezzaTitolo << " caratteri): ";
    cin >> titoloInput;

    int durataInput, annoInput;

    cout << "Inserisci durata: ";
    cin >> durataInput;
    cout << "Inserisci anno: ";
    cin >> annoInput;

    film p(titoloInput, durataInput, annoInput);
    p.stampaFilm();

    // Chiamata alla funzione per creare un nuovo film
    film *nuovo = creaSequel(&p, p.getAnno()+3);
    cout << "Nuovo film creato:" <<endl;
    nuovo->stampaFilm();

    // Liberazione della memoria allocata dinamicamente
    delete[] titoloInput;

    return 0;
}
