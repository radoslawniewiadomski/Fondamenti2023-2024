#include <iostream>
using namespace std;


struct film
{
    int id;
    char* titolo;
    int durata;
    int anno;
};

int main()
{
    film* p = new film;

    int n;
    cout << "Quanto e' lungo il titolo del film?" ;
    cin >> n;
    p->titolo = new char[n];
    cout << "Inserisci il titolo: "  << "? ";
    cin >>  p->titolo;
    cout << "Inserisci durata (in minuti):  ";
    cin >> p->durata;
    cout << "Inserisci l'anno di produzione:  ";
    cin >> p->anno;

    cout << "Titolo: " << p->titolo << endl;

    delete [] p->titolo;
    delete p;

    return 0;
}
