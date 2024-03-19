#include <iostream>
using namespace std;

class Punto {
  	double _x;
	double _y;

	public:
	Punto();
	Punto(double x, double y);
	Punto(const Punto& p);
	void cambiaX (double f);
	double leggiX ();
	void riscala(double f);
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


void Punto::riscala(double f){
	_x *= f;
	_y *= f;
}

void Punto::cambiaX(double f) {
	_x = f;
}

double Punto::leggiX() {
	return _x;
}

int main(){
     Punto *pp = new Punto (0);
     pp->riscala(0.5);
     cout<<pp->leggiX();
     return 0;
}
