#include <iostream>
#include <math.h>
using namespace std;

class Punto {
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
Punto::Punto() {
    _x = -1;
    _y = -1;
}

//costruttore con dei parametri
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

//destruttore che non fa niente utile
Punto::~Punto() {
    cout << "Questo e' il distruttore" << endl;
}

//////////////////////////////////////////////////////7

Punto* creaPuntiDistanti(Punto* punto) {
    Punto* punti = new Punto[10];
    double angleIncrement = 2 * M_PI / 10;
    double radius = 100;

    for (int i = 0; i < 10; ++i) {
        double angle = i * angleIncrement;
        double newX = punto->getX() + radius * cos(angle);
        double newY = punto->getY() + radius * sin(angle);
        punti[i].setX(newX);
        punti[i].setY(newY);
    }

    return punti;
}

int main() {
    Punto* p2 = new Punto(10, 10);
    p2->stampaPunto();

    Punto* puntiCreati = creaPuntiDistanti(p2);
    for (int i = 0; i < 10; ++i) {
        puntiCreati[i].stampaPunto();
    }

    delete[] puntiCreati;
    delete p2;
    return 0;
}
