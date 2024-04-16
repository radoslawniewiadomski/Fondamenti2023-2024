#include <iostream>
#include <iostream>
#include <cmath> // Per la funzione sqrt

using namespace std;

class Punto
{
    // Attributi privati
    double _x;
    double _y;

public:
    // Costruttori
    Punto();
    Punto(double x, double y);

    // Distruttore
    ~Punto();

    // Modificatori
    void setX(double x);
    void setY(double y);

    // Selettori
    double getX();
    double getY();

    // Altri metodi
    void stampaPunto();

    // Dichiarazione di funzione amica
    friend double calcolaDistanza(const Punto& p1, const Punto& p2);
};

///////////////////////////////////////////////////////////////////


// Definizione dei metodi della classe Punto
Punto::Punto()
{
    _x = -1;
    _y = -1;
}

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

Punto::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}

// Definizione della funzione amica
double calcolaDistanza(const Punto& p1, const Punto& p2)
{
    double distanza = sqrt(pow(p2._x - p1._x, 2) + pow(p2._y - p1._y, 2));
    return distanza;
}

int main()
{
    Punto punto1(1, 2);
    Punto punto2(4, 6);

    punto1.stampaPunto();
    punto2.stampaPunto();

    double distanza = calcolaDistanza(punto1, punto2);
    cout << "Distanza tra i due punti: " << distanza << endl;

    return 0;
}
