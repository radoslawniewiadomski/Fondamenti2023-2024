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
    Punto* p2 = new Punto(10, 20);
    p2->stampaPunto();

    p2->setX(30);
    p2->stampaPunto();

    delete p2;
    return 0;
}
