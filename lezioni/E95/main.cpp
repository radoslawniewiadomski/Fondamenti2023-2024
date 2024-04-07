#include <iostream>
using namespace std;

class Punto
{
    // 2 attributi privati
    double _x;
    double _y;

public:
    // costruttori
    Punto();
    Punto(double x, double y);

    // destruttore
    ~Punto();

    // modificatori
    void setX(double x);
    void setY(double y);

    // selettori
    double getX();
    double getY();

    // altri metodi
    void stampaPunto();
};

// definizione dei metodi
// costruttore "default"
Punto::Punto()
{
    _x = -1;
    _y = -1;
}

//destruttore che non fa niente
Punto::~Punto()
{
    cout << "Sono distruttore" << endl;
}

// costruttore con dei parametri
Punto::Punto(double x, double y)
{
    _x = x;
    _y = y;
}

void Punto::setX(double x)
{
    _x = x;
}

void Punto::setY(double y)
{
    _y = y;
}

double Punto::getX()
{
    return _x;
}

double Punto::getY()
{
    return _y;
}

void Punto::stampaPunto()
{
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funzione per calcolare la media delle coordinate dei punti
void calcolaMediaCoordinate(Punto punti[], int size)
{
    double sommaX = 0, sommaY = 0;
    for (int i = 0; i < size; ++i)
    {
        sommaX += punti[i].getX();
        sommaY += punti[i].getY();
    }
    double mediaX = sommaX / size;
    double mediaY = sommaY / size;
    cout << "La media delle coordinate dei punti è: (" << mediaX << ", " << mediaY << ")" << endl;
}

/* VERSIONE 2
Punto calcolaMediaPunti(Punto punti[], int size) {
    double sommaX = 0, sommaY = 0;

    for (int i = 0; i < size; ++i) {
        sommaX += punti[i].getX();
        sommaY += punti[i].getY();
    }

    double mediaX = sommaX / size;
    double mediaY = sommaY / size;

    return Punto(mediaX, mediaY);
}
*/


int main()
{
    // Creazione dell'array di 10 punti
    Punto punti[10];

    // Inizializzazione dei punti con coordinate da (1, 1) a (10, 10)
    for (int i = 0; i < 10; ++i)
    {
        punti[i].setX(i + 1);
        punti[i].setY(i + 1);
    }

    // Stampa dei punti
    for (int i = 0; i < 10; ++i)
    {
        punti[i].stampaPunto();
    }

    // Calcolo e stampa la media delle coordinate
    calcolaMediaCoordinate(punti, 10);

    /* VERSIONE 2
    // Calcolo la media delle coordinate
    Punto media = calcolaMediaPunti(punti, 10);

    // Stampa la media delle coordinate
    cout << "La media delle coordinate dei punti è: (" << media.getX() << ", " << media.getY() << ")" << endl;
    */

    return 0;
}
