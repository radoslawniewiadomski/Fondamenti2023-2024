#include <iostream>
#include <cstring>
using namespace std;

class Punto
{
    double _x;
    double _y;
    char *c;

public:
    Punto();
    Punto(double x, double y);

    void cambiaNome(const char *x);
    void stampa();
};

Punto::Punto()
{
    _x = 0.0;
    _y = 0.0;
    c = new char[20];
    strcpy(c, "Uno");
}

Punto::Punto(double x, double y) : _x(x), _y(y)
{
    c = new char[20];
    strcpy(c, "Uno");
}

void Punto::cambiaNome(const char *x)
{
    delete[] c; // Dealloca la memoria precedente per evitare memory leak
    c = new char[strlen(x) + 1];
    strcpy(c, x);
}

void Punto::stampa()
{
    cout << c << endl;
    cout << _x<< endl;
    cout << _y<< endl;
}

int main()
{
    Punto punto1;
    punto1.cambiaNome("Due");

    Punto punto2(5,6);
    punto2.cambiaNome("Tre");

    punto1.stampa();
    punto2.stampa();
    return 0;
}
