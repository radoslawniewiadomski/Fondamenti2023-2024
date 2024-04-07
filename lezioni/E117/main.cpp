#include <iostream>
using namespace std;

template <typename T>
class Punto
{
    T _x;
    T _y;

public:
    Punto();
    Punto(T x, T y);

    ~Punto();

    void setX(T x);
    void setY(T y);

    T getX();
    T getY();

    void stampaPunto();
};

template <typename T>
Punto<T>::Punto()
{
    _x = -1;
    _y = -1;
}

template <typename T>
Punto<T>::Punto(T x, T y)
{
    _x = x;
    _y = y;
}

template <typename T>
void Punto<T>::setX(T x)
{
    _x = x;
}

template <typename T>
void Punto<T>::setY(T y)
{
    _y = y;
}

template <typename T>
T Punto<T>::getX()
{
    return _x;
}

template <typename T>
T Punto<T>::getY()
{
    return _y;
}

template <typename T>
void Punto<T>::stampaPunto()
{
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

template <typename T>
Punto<T>::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}


int main()
{
    Punto<double> p(3.5, 2.8);
    Punto<int> q(6, 8);

    cout << "Coordinate di p: "
         << p.getX() << ", " << p.getY() << endl;
    cout << "Coordinate di q: "
         << q.getX() << ", " << q.getY() << endl;

    return 0;
}
