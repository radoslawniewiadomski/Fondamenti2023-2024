#include <iostream>
using namespace std;

struct film
{
    int id;
    char titolo[50];
    int durata;
    int anno;
};


int main()
{
    film* elencoFilm[5];
    for (int i = 0; i < 5; ++i)
    {
        film film1;
        cout << "Inserisci il titolo del film " << i + 1 << ": ";
        cin >> film1.titolo;
        cout << "Inserisci durata (in minuti): ";
        cin >> film1.durata;
        cout << "Inserisci l'anno di produzione: ";
        cin >> film1.anno;
        film1.id=i;
        elencoFilm[i]=&film1;
    }

    // Stampa i titoli dei film
    cout << "\nTitoli dei film:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << "Film " << i + 1 << ": " << elencoFilm[i]->titolo<< ", durata "<<elencoFilm[i]->durata << " minuti. " << endl;
    }
    return 0;
}
