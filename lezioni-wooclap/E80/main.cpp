#include <iostream>
using namespace std;

class Punto {
  	double _x;
	double _y;

	public:
	Punto();
	Punto(double x, double y);

	void cambiaX (double f);
	double leggiX ();
};

Punto::Punto() {
	_x = 0.0;
    _y = 0.0;
}
Punto::Punto(double x, double y) {
	_x = x;
	_y = y;
}
void Punto::cambiaX(double f) {
	_x = f;
}

double Punto::leggiX() {
	return _x;
}

int main(){
    Punto punto1;
    punto1.cambiaX(1000);

    Punto punto2;
    punto2.cambiaX(200);

     cout<<&punto1<<endl;
     cout<<&punto2<<endl;

     punto2=punto1;

     cout<<&punto1<<endl;
     cout<<&punto2<<endl;

     punto1.cambiaX(300);
     cout<<punto2.leggiX();

     return 0;
}
