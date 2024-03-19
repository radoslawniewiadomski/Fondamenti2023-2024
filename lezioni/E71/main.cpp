#include <iostream>
using namespace std;

struct film {

    char titolo [20];
    int durata;
    int anno;
};

void stampaFilm(film p)
{
    cout << "Titolo: " << p.titolo << endl;
    cout << "Durata: " << p.durata << " minuti" << endl;
    cout<< "Anno: " << p.anno << endl;
}

int main(){
    film p;
    cout << "Inserisci il titolo (max 20 char): " ;
    cin >>  p.titolo;
    cout << "Inserisci durata: ";
    cin >> p.durata;
    cout << "Inserisci anno: ";
    cin >> p.anno;
    stampaFilm(p);
    return 0;
}


/*
class film {
    public:

    char _titolo [20];
    int _durata;
    int _anno;

    void stampaFilm();
};

void film::stampaFilm()
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout<< "Anno: " << _anno << endl;
}

int main(){
    film p;
    cout << "Inserisci il titolo (max 20 char): " ;
    cin >>  p._titolo;
    cout << "Inserisci durata: ";
    cin >> p._durata;
    cout << "Inserisci anno: ";
    cin >> p._anno;
    p.stampaFilm();
    return 0;
}

*/

