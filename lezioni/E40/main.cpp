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
    const int numFilm = 3;
    film* elencoFilm[numFilm];

    for (int i = 0; i < numFilm; ++i)
    {
        elencoFilm[i] = new film;
        cout << "Inserisci il titolo del film " << i + 1 << ": ";
        cin >> elencoFilm[i]->titolo;
        cout << "Inserisci durata (in minuti): ";
        cin >> elencoFilm[i]->durata;
        cout << "Inserisci anno di produzione: ";
        cin >> elencoFilm[i]->anno;
        elencoFilm[i]->id = i + 1;
    }
    cout << "Titoli dei film: ";
    for (int i = 0; i < numFilm; ++i)
    {
        cout << "Film " << i + 1 << ": " << elencoFilm[i]->titolo << endl;
    }
    for (int i = 0; i < numFilm; ++i)
    {
        delete elencoFilm[i];
    }
    return 0;
}
