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
  // costruttore di default
   Punto* pa = new Punto();

   // costruttore con parametri
   Punto* pb = new Punto(10, 20);

   // costruttore di copia
   Punto* pc = new Punto(*pa);

  delete pa;
  delete pb;
  delete pc;

   return 0;
   }

