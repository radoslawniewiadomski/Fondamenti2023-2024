#include <iostream>
using namespace std;

class Punto
{
    //2 attibuti privati
    double _x;
    double _y;

public:
    //costruttori
    Punto();
    Punto(double x, double y);

    //destruttore
    ~Punto();

    //modificatori
    void setX(double x);
    void setY(double y);

    //selettori
    double getX();
    double getY();

    //altri metodi
    void stampaPunto();
};
//definizione dei metodi
//costruttore "default"
Punto::Punto()
{
    _x = -1;
    _y = -1;
}

//costruttore con dei parametri
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

//destruttore che non fa niente utile
Punto::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}

int main()
{
    // Creazione di due oggetti Punto
    Punto punto1(3.5, 4.2);
    Punto punto2(1.8, 2.5);

    // Stampa delle coordinate dei punti prima dell'operazione
    cout << "Coordinate del primo punto: ";
    punto1.stampaPunto();
    cout << "Coordinate del secondo punto: ";
    punto2.stampaPunto();

    // Test dell'operatore di assegnamento
    cout << "\nTest dell'operatore di assegnamento:\n";
    punto1 = punto2;
    cout << "Dopo l'assegnamento, coordinate del primo punto: ";
    punto1.stampaPunto();

    return 0;
}
