#include <iostream>
#include <cstring>
using namespace std;

class Punto {
    double _x;
    double _y;
    char *c;

public:
    Punto();
    Punto(const Punto &p); // Costruttore di copia
    void cambiaNome(const char *x);
    void stampaNome();
};

Punto::Punto() {
    _x = 0.0;
    _y = 0.0;
    c = new char[20];
    strcpy(c, "Uno");
}

Punto::Punto(const Punto &p)  {
    _x=p._x;
    _y=p._y;
    c = new char[strlen(p.c) + 1];
    strcpy(c, p.c);
}

void Punto::cambiaNome(const char *x) {
    delete[] c;
    c = new char[strlen(x) + 1];
    strcpy(c, x);
}

void Punto::stampaNome() {
    cout << c;
}

int main() {
    Punto punto1;
    punto1.cambiaNome("Due!");

    //punto2.cambiaNome("Tre");
    Punto punto2 (punto1);

    punto1.cambiaNome("Quattro!");

    punto2.stampaNome();
    return 0;
}
