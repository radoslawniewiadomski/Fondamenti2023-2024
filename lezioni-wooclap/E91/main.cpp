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

void sposta(Punto p, double radius){
        double angle = 0;
        double newX = p.getX() + radius * cos(angle);
        double newY = p.getY() + radius * sin(angle);
        p.setX(newX);
        p.setY(newY);
        cout<<"NewX: "<<newX<<" NewY: "<<newY<<endl;
    }

int main() {
    Punto* p2 = new Punto(0, 0);
    p2->stampaPunto();
    sposta(*p2,100);
    p2->stampaPunto();

    delete p2;
    return 0;
}
