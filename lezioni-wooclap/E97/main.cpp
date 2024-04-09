#include <iostream>
using namespace std;
class Punto
{
    double _x;
    double _y;

public:
    Punto(double x, double y);
    Punto();
    ~Punto();
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void stampaPunto();
};

Punto::Punto()
{
    _x=-1;
    _y=-1;
}
Punto::~Punto()
{
    cout << "Sono distruttore" << endl;
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

int main()
{
    Punto punti[10];
    double sommaX =0;
    double sommaY =0;

    for (int i = 0; i < 10; ++i)
    {
        sommaX += punti[i].getX();
        sommaY += punti[i].getY();
    }
    double mediaX = sommaX / 10;
    double mediaY = sommaY / 10;

    cout<<mediaX<<"; "<<mediaY;
    return 0;
}
