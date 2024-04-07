#include <iostream>
#include <cstring>
using namespace std;

class film
{
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
film::film()
{
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

film::film(char* titolo, int durata, int anno)
{
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
}

film::film(const film& otherFilm)
{
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;
}

film::~film()
{
    delete[] _titolo;
}

char* film::getTitolo() const
{
    return _titolo;
}

void film::setTitolo(const char* titolo)
{
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

int film::getDurata() const
{
    return _durata;
}

void film::setDurata(int durata)
{
    _durata = durata;
}

int film::getAnno() const
{
    return _anno;
}

void film::setAnno(int anno)
{
    _anno = anno;
}

void film::stampaFilm()
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout << "Anno: " << _anno << endl;
}

/////////////////////////////////////////////////////////////////////////////

int main() {
    int numFilm;

    cout << "Quanti film vuoi inserire? ";
    cin >> numFilm;

    film** listaFilm = new film*[numFilm]; // Array di puntatori a film

    // Richiesta all'utente di inserire i dati per ciascun film
    for (int i = 0; i < numFilm; i++) {
        int lunghezzaTitolo;
        cout << "Inserisci la lunghezza del titolo del " << i + 1 << " film: ";
        cin >> lunghezzaTitolo;

        // Allocazione dinamica della memoria per il titolo del film
        char* titolo = new char[lunghezzaTitolo + 1];

        cout << "Inserisci il titolo del " << i + 1 << " film: (massimo " << lunghezzaTitolo << " caratteri): ";
        cin >> titolo;

        int durata, anno;

        cout << "Inserisci la durata in minuti del " << i + 1 << " film: ";
        cin >> durata;

        cout << "Inserisci l'anno di produzione del " << i + 1 << " film: ";
        cin >> anno;

        listaFilm[i] = new film(titolo, durata, anno); // Creazione del nuovo film
        delete[] titolo; // Liberiamo la memoria allocata per il titolo
    }

    // Stampa dei film
    for (int i = 0; i < numFilm; i++) {
        cout << "Film " << i + 1 << ":" << endl;
        listaFilm[i]->stampaFilm();
        cout << endl;
    }

    // Deallocazione della memoria
    for (int i = 0; i < numFilm; i++){
        delete listaFilm[i];
    }
    delete[] listaFilm;

    return 0;
}
