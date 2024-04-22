#include <iostream>
#include <cstring>

using namespace std;

class Person {
    char _nome[32];
    char _cognome[32];
public:
    Person(const char* nome, const char* cognome);
    Person();
    void stampa() const;

    friend ostream& operator<<(ostream& os, const Person& p);
};

Person::Person() {
    strcpy(_nome, "N/D");
    strcpy(_cognome, "N/D");
}

Person::Person(const char* nome, const char* cognome) {
    strcpy(_nome, nome);
    strcpy(_cognome, cognome);
}

void Person::stampa() const {
    cout << "Nome: " << _nome << ", Cognome: " << _cognome;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << "Nome: " << p._nome << ", Cognome: " << p._cognome;
    return os;
}

class Film {
    char* titolo;
    int durata;
    int anno;

public:
    Film();
    Film(const char* titolo, int durata, int anno);
    Film(const Film& otherFilm);
    ~Film();

    friend ostream& operator<<(ostream& os, const Film& film);

    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    void stampa() const;
};

Film::Film() {
    titolo = new char[4];
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

void Film::stampa() const {
    cout << "Titolo: " << titolo << ", Durata: " << durata << " minuti, Anno: " << anno;
}

ostream& operator<<(ostream& os, const Film& film) {
    os << "Titolo: " << film.titolo << ", Durata: " << film.durata << " minuti, Anno: " << film.anno;
    return os;
}

template <typename T, typename U>
class Coppia {
    T primo;
    U secondo;

public:
    Coppia(T p, U s) : primo(p), secondo(s) {}

    void stampaCoppia();

    template <typename Z>
    void stampaOggetto(const Z& oggetto);
};

template <typename T, typename U>
 void Coppia<T, U>::stampaCoppia() {
    cout << "Primo elemento: ";
    stampaOggetto(primo);
    cout << ", Secondo elemento: ";
    stampaOggetto(secondo);
    cout << endl;
}

template <typename T, typename U>
template <typename Z>
 void Coppia<T, U>::stampaOggetto(const Z& oggetto) {
    oggetto.stampa();
}

/////////////////////////////////////////////////////////////

int main() {

    Coppia<Film, Person> coppia1(Film("Shark", 125, 1975),Person("Steven", "Spielberg") );
    coppia1.stampaCoppia();

    Coppia<Person, Film> coppia2(Person("Andrew", "Adamson"), Film("Shrek", 120, 2001));
    coppia2.stampaCoppia();

    return 0;
}
