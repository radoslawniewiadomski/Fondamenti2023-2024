#include <iostream>
using namespace std;

class Punto {
 	double _p[2];
	public:
	void cambiaX (double f);
	double leggiX ();
};

void Punto::cambiaX(double f) {
	_p[0] = f;
}

double Punto::leggiX() {
	return _p[0];
}

int main() {
     Punto p;
     p.cambiaX(100);
     cout<<p.leggiX();

     return 0;
}
