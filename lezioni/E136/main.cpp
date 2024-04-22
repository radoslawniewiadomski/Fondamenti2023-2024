#include <iostream>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()
#include <cstring>

using namespace std;

class Person
{
    char _nome[32];
    char _cognome[32];
public:
    Person(const char* nome, const char* cognome);
    Person();
    void stampa() const;

    //operatore
    friend ostream& operator<<(ostream& os, const Person& p);

};

Person::Person()
{
    strcpy(_nome, "N/D");
    strcpy(_cognome, "N/D");
}

Person::Person(const char* nome, const char* cognome)
{
    strcpy(_nome, nome);
    strcpy(_cognome, cognome);
}

void Person::stampa() const
{
    cout << "Nome: " << _nome << ", Cognome: " << _cognome << endl;
}


template<typename T, int n>
class Vettore
{
    T dati[n];
public:
    Vettore();

    void stampa();
};

template<typename T, int n>
Vettore<T,n>::Vettore()
{
}

template<typename T, int n>
void Vettore<T,n>::stampa()
{
    for (int i = 0; i < n; i++) cout  << dati[i] << " ";
    cout << endl;
}


ostream& operator<<(ostream& os, const Person& p)
{
    os << "Name: " << p._nome << ", Cognome: " << p._cognome;
    return os;
}

int main()
{
    srand(time(0));
    Vettore<Person, 2> v1; // Vettore di 5 double
    v1.stampa(); // Stampa il vettore di 5 double

    Vettore<int, 8> v2;
    v2.stampa();

    return 0;
}





