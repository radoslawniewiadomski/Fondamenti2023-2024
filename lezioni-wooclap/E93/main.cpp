#include <iostream>
#include <cmath>
using namespace std;

class Punto {
    double _x;
    double _y;

public:
    Punto();
    Punto(double x, double y);
    ~Punto();
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void stampaPunto();
    void sposta(double);
};

Punto::Punto() {
    _x = -1;
    _y = -1;
}

Punto::Punto(double x, double y) {
    _x = x;
    _y = y;
}

void Punto::setX(double x) {
    _x = x;
}

void Punto::setY(double y) {
    _y = y;
}

double Punto::getX() {
    return _x;
}

double Punto::getY() {
    return _y;
}

void Punto::stampaPunto() {
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

Punto::~Punto() {
    cout << "Questo e' il distruttore" << endl;
}

void Punto::sposta(double radius){
        double angle = M_PI;
        _x = _x + radius * cos(angle);
        _y = _y + radius * sin(angle);
    }

int main() {
    Punto* p2 = new Punto(0, 0);
    p2->stampaPunto();
    p2->sposta(100);
    p2->stampaPunto();
    delete p2;
    return 0;
}
