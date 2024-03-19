#include <iostream>
using namespace std;

class Punto
{
    void test(int n);
public:
    double _x;
    double _y;
    void riscala(double f);
};

int main()
{
    Punto p;
    p._x = 100;	// OK
    p._y = 200;	// OK
    p.riscala(2.0);	// OK
    p.test(3);		// ERRORE! test è membro privato!
    return 0;
}
