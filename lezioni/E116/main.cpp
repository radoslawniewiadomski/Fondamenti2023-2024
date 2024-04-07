#include <iostream>
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

    //operatori
    friend ostream& operator<<(ostream& os, const Punto& p);
    friend istream& operator>>(istream& is, Punto& p);
    Punto operator+(Punto p);

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
    cout << "Sono distruttore" << endl;
}


Punto Punto::operator+(Punto p)
{
    Punto q(_x + p._x, _y + p._y);
    return q;
}

ostream& operator<<(ostream& os, const Punto& p){
  os << '(' << p._x << ',' << p._y << ')';
  return os;
}
istream& operator>>(istream& is, Punto& p){
  is >> p._x >> p._y;
  return is;
}


int main() {
	Punto p(5.0, 2.0);
    Punto q(4.0, 1.0);

    cout << "La somma di " << p << " e " << q << " vale " << p + q << endl;
	return 0;
}
