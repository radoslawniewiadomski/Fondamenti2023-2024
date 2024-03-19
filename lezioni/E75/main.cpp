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
     Punto *pp;
     pp->_x = 100;
     pp->_y = 200;
     pp->riscala(0.5);
     cout<<pp->_x;
     return 0;
}
