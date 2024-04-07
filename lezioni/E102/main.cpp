#include <iostream>
#include <cstring>

using namespace std;

class Libro {
    char* autore;
    char* titolo;
    int anno;

public:
    // Costruttori
    Libro();
    Libro(const char* autore, const char* titolo, int anno);
    // Costruttore di copia
    Libro(const Libro& otherLibro);
    // Distruttore
    ~Libro();
    // Selettori e modificatori
    const char* getAutore() const;
    void setAutore(const char* autore);
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getAnno() const;
    void setAnno(int anno);
};

// Definizioni delle funzioni di Libro
Libro::Libro() {
    autore = new char[1];
    strcpy(autore, "");
    titolo = new char[1];
    strcpy(titolo, "");
    anno = 0;
}

Libro::Libro(const char* autore, const char* titolo, int anno) {
    this->autore = new char[strlen(autore) + 1];
    strcpy(this->autore, autore);
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
    this->anno = anno;
}

Libro::Libro(const Libro& otherLibro) {
    autore = new char[strlen(otherLibro.autore) + 1];
    strcpy(autore, otherLibro.autore);
    titolo = new char[strlen(otherLibro.titolo) + 1];
    strcpy(titolo, otherLibro.titolo);
    anno = otherLibro.anno;
}

Libro::~Libro() {
    delete[] autore;
    delete[] titolo;
}

const char* Libro::getAutore() const {
    return autore;
}

void Libro::setAutore(const char* autore) {
    delete[] this->autore;
    this->autore = new char[strlen(autore) + 1];
    strcpy(this->autore, autore);
}

const char* Libro::getTitolo() const {
    return titolo;
}

void Libro::setTitolo(const char* titolo) {
    delete[] this->titolo;
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
}

int Libro::getAnno() const {
    return anno;
}

void Libro::setAnno(int anno) {
    this->anno = anno;
}

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
    // Metodo per trovare il libro più vecchio nella libreria
    Libro* trovaLibroPiuVecchio() const;
};

// Definizioni delle funzioni di Libreria
Libreria::Libreria(int id) {
    this->id = id;
    libri = nullptr;
    numLibri = 0;
}

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

Libro* Libreria::trovaLibroPiuVecchio() const {
    if (numLibri == 0) {
        return nullptr; // Se la libreria è vuota, restituisce nullptr
    }

    Libro* libroPiuVecchio = &libri[0]; // Supponiamo il primo libro come il più vecchio

    for (int i = 1; i < numLibri; ++i) {
        if (libri[i].getAnno() < libroPiuVecchio->getAnno()) {
            libroPiuVecchio = &libri[i];
        }
    }

    return libroPiuVecchio;
}

int main() {
    int numLibri;

    cout << "Quanti libri contiene la libreria? ";
    cin >> numLibri;

    Libreria libreria(1); // Creiamo una libreria con ID 1

    for (int i = 0; i < numLibri; ++i) {
        char autore[100];
        char titolo[100];
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

    // Troviamo e stampiamo il libro più vecchio nella libreria
    const Libro* libroPiuVecchio = libreria.trovaLibroPiuVecchio();
    if (libroPiuVecchio != nullptr) {
        cout << "Il libro piu vecchio nella libreria e:" << endl;
        cout << "Autore: " << libroPiuVecchio->getAutore() << endl;
        cout << "Titolo: " << libroPiuVecchio->getTitolo() << endl;
        cout << "Anno di stampa: " << libroPiuVecchio->getAnno() << endl;
    } else {
        cout << "La libreria e vuota." << endl;
    }

    return 0;
}
