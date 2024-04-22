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
    // Distruttore
    ~Libro();
    // Metodi di accesso
    const char* getAutore() const;
    void setAutore(const char* autore);
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getAnno() const;
    void setAnno(int anno);
};

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

// Definizioni dei metodi della classe Libro
Libro::Libro() : autore(nullptr), titolo(nullptr), anno(0) {}

Libro::Libro(const char* autore, const char* titolo, int anno) : anno(anno) {
    this->autore = new char[strlen(autore) + 1];
    strcpy(this->autore, autore);
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
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

// Definizioni dei metodi della classe Libreria
Libreria::Libreria(int id) : id(id), libri(nullptr), numLibri(0) {}

Libreria::~Libreria() {
    for (int i = 0; i < numLibri; ++i) {
        delete[] libri[i].getAutore();
        delete[] libri[i].getTitolo();
    }
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

        Libro libro;
        libro.setAutore(autore);
        libro.setTitolo(titolo);
        libro.setAnno(anno);

        libreria.inserisciLibro(libro);
    }

    cout << "La libreria contiene " << libreria.getNumLibri() << " libri." << endl;

    return 0;
}

