#include <iostream>
#include <string.h>
using namespace std;

struct film
{
    int id;
    char titolo[50];
    int durata;
    int anno;
};

void stampaFilm(film* f)
{
    cout << "ID: " << f->id << endl;
    cout << "Titolo: " << f->titolo << endl;
    cout << "Durata: " << f->durata << " minuti" << endl;
    cout<< "Anno: " << f->anno << endl;
}

int main()
{
    film elencoFilm[5];
    char titolo[50];
    int durata;
    int anno;

    for (int i = 0; i < 5; ++i)
    {
        cout << "Inserisci il titolo per il film " << i + 1 << ": ";
        cin >> titolo;
        cout << "Inserisci durata (in minuti): ";
        cin >> durata;
        cout << "Inserisci anno: ";
        cin >> anno;
        elencoFilm[i].id = i + 1;
        elencoFilm[i].durata = durata;
        elencoFilm[i].anno = anno;
        strcpy(elencoFilm[i].titolo, titolo);
    }
    for (int i = 0; i < 5; ++i)
    {
        cout << "Film " << i + 1 << endl;
        stampaFilm(&elencoFilm[i]);
        cout << endl;
    }
}
