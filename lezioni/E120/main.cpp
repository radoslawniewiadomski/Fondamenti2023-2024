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
    // Distruttore
    ~film();

    //operatori
 bool operator>(const film& film2) const ;
     film& operator=(const film& otherFilm);


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

bool film::operator>(const film& film2) const {
    // Confronto sulla durata dei film
    if (getDurata() > film2.getDurata()) return true;
    return false;
}

    film& film::operator=(const film& otherFilm) {
        if (this != &otherFilm) {
            delete[] _titolo;
            _titolo = new char[strlen(otherFilm._titolo) + 1];
            strcpy(_titolo, otherFilm._titolo);
            _durata = otherFilm._durata;
            _anno = otherFilm._anno;
        }
        return *this;
    }


/* SECONDA VERSIONE
bool film::operator>(const film& film2) {
    // Confronto sulla data di produzione dei film (dove maggiore significa più vecchio)
    return getAnno() < film2.getAnno();
}
*/

film::film(char* titolo, int durata, int anno) {
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
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

///////////////////////////////////////////////////////////////

class Impiegato {
private:
    char nome[32];
    char cognome[32];
public:
    Impiegato(const char* _nome, const char* _cognome);
    Impiegato();

    // Operatore ">" sovraccaricato per confrontare due impiegati in base al cognome
    bool operator>(const Impiegato& imp) const;

    void stampa() const;
};

Impiegato::Impiegato() {
    strcpy(nome, "N/D");
    strcpy(cognome, "N/D");

}


Impiegato::Impiegato(const char* _nome, const char* _cognome) {
    strcpy(nome, _nome);
    strcpy(cognome, _cognome);
}

bool Impiegato::operator>(const Impiegato& imp) const {
    if (strcmp(cognome, imp.cognome) > 0) return true;
     return false;
}

void Impiegato::stampa() const {
    cout << "Nome: " << nome << ", Cognome: " << cognome << endl;
}

///////////////////////////////////////////////////////////////

template<typename T>
void swap2(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void BubbleSort (T v[], int n) {
	int i, j;
	T tmp;
	for (i = n - 1; i > 0; i--)
		for (j = 0; j < i; j++)
      		if (v[j] > v[j+1]) {
				tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
	}
}


int main() {
    int a[5] = {3, 2, 6, 1, 4};
    Impiegato imp[3] = {{"Mario", "Rossi"}, {"Paola", "Bianchi"}, {"Riccardo", "Bianccardi"}};

     film filmArray[5] = {
        {"Matrix", 120, 1999},
        {"Inception", 148, 2010},
        {"Interstellar", 169, 2014},
        {"Shawshank", 142, 1993},
        {"Pulp", 154, 1994}
    };

    cout << "Prima di ordinare:" << endl;
    for (int i = 0; i < 5; ++i) {
        filmArray[i].stampaFilm();
    }

    BubbleSort<int>(a, 5);
    BubbleSort<Impiegato>(imp, 3);
    BubbleSort<film>(filmArray, 5);

    cout << "\nDopo l'ordinamento dei film:" << endl;
    for (int i = 0; i < 5; ++i) {
        filmArray[i].stampaFilm();
    }

    return 0;
}
