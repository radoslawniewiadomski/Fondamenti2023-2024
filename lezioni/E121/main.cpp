#include "Punto.h"

int main()
{
    Punto* p2 = new Punto(10, 20);
    p2->stampaPunto();

    p2->setX(30);
    p2->stampaPunto();

    delete p2;
    return 0;
}
