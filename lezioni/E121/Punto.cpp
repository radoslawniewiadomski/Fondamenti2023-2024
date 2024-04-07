#include "Punto.h"
#include <iostream>
using namespace std;

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

//destruttore che non fa niente
Punto::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}
