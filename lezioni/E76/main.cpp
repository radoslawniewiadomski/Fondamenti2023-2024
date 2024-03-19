#include <iostream>
using namespace std;

class Punto {
public:
	Punto();
	Punto(double x, double y);
	Punto(const Punto& p);
	void riscala(double f);

private:
 	double _x;
	double _y;
};

Punto::Punto() {
	_x = 0.0;
    _y = 0.0;
}

Punto::Punto(double x, double y) {
	_x = x;
	_y = y;
}

Punto::Punto(const Punto& p) {
	_x = p._x;
	_y = p._y;
}

int main() {
   Punto p1;
   // costruttore di default
   //x e y valgono 0

   Punto p2(10, 20);
   // costruttore con parametri
   // x e 10, y e 20

   Punto p3(p2);
   // costruttore di copia
   // x e 10, y e 20
   return 0;
   }
