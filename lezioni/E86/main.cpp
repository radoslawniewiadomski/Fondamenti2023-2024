#include <iostream>
using namespace std;

class Punto {
    public:
 	double _x;
	double _y;
	void riscala(double f);
};

void Punto::riscala(double f)
{
	_x *= f;
	_y *= f;
}


int main()
{
  Punto p;
     p._x = 100;
     p._y = 200;
     p.riscala(0.5);
     cout<<p._x;
    return 0;
}
