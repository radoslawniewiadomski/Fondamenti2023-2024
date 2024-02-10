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
    film* elencoFilm[2];

    film film1;
    cout << "Inserisci il titolo del primo film: ";
    cin >> film1.titolo;
    cout << "Inserisci durata (in minutes): ";
    cin >> film1.durata;
    cout << "Inserisci anno di produzione: ";
    cin >> film1.anno;
    film1.id=0;
    elencoFilm[0]=&film1;

    film film2;
    cout << "Inserisci il titolo del secondo film: ";
    cin >> film2.titolo;
    cout << "Inserisci durata (in minutes): ";
    cin >> film2.durata;
    cout << "Inserisci anno di produzione:  ";
    cin >> film2.anno;
    film2.id=2;
    elencoFilm[1]=&film2;

    for (int i = 0; i < 2; ++i)
    {
        cout << "Film " << i + 1 << ": " << elencoFilm[i]->titolo << ", durata: "<<elencoFilm[i]->durata << "minuti. " << endl;
    }
    return 0;
}

