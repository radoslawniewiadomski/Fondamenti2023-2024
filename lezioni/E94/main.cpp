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

    return 0;
}
