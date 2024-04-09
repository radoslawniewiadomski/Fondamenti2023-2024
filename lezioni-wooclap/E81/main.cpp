#include <iostream>
using namespace std;

class Punto {
  	double _x;
	double _y;
	int c [3];

	public:
	Punto();
	Punto(double x, double y);

	void cambiaColore (int, int, int);
	void stampaColore ();
};

Punto::Punto() {
	_x = 0.0;
    _y = 0.0;
    c[0]=0;c[1]=0;c[2]=0;
}

void Punto::cambiaColore(int r, int g, int b) {
    c[0]=r; c[1]=g;c[2]=b;
}

void Punto::stampaColore() {
	cout<<"rosso: "<<c [0]<<", ";
	cout<<"verde: "<<c [1]<<", ";
	cout<<"blue: " <<c  [2]<<", ";
}

int main(){
    Punto punto1;
    punto1.cambiaColore(255,0,0);

     Punto punto2;
     punto2.cambiaColore(0,255,0);
     punto2=punto1;

     punto1.cambiaColore(0,0,255);
     punto2.stampaColore();

     return 0;
}
