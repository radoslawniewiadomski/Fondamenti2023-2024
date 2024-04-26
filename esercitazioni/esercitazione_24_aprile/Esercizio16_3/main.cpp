#include <iostream>
using namespace std;

template<typename T>
class Tripla {
private:
    T primo;
    T secondo;
    T terzo;

public:
    Tripla(T p, T s, T t);

    T trovaMassimo() const;

    T trovaMinimo() const;

    void ordina();

    void stampaTripla() const;
};

template<typename T>
Tripla<T>::Tripla(T p, T s, T t) : primo(p), secondo(s), terzo(t) {}

template<typename T>
T Tripla<T>::trovaMassimo() const {
    T massimo = primo;
    if (secondo > massimo)
        massimo = secondo;
    if (terzo > massimo)
        massimo = terzo;
    return massimo;
}

template<typename T>
T Tripla<T>::trovaMinimo() const {
    T minimo = primo;
    if (secondo < minimo)
        minimo = secondo;
    if (terzo < minimo)
        minimo = terzo;
    return minimo;
}

template<typename T>
void Tripla<T>::ordina() {
    T temp;
    if (primo > secondo) {
        temp = primo;
        primo = secondo;
        secondo = temp;
    }
    if (primo > terzo) {
        temp = primo;
        primo = terzo;
        terzo = temp;
    }
    if (secondo > terzo) {
        temp = secondo;
        secondo = terzo;
        terzo = temp;
    }
}

template<typename T>
void Tripla<T>::stampaTripla() const {
    cout << "Tripla: " << primo << ", " << secondo << ", " << terzo << endl;
}

int main() {
    Tripla<int> triplaInt(5, 3, 7);
    triplaInt.stampaTripla(); // Output: Tripla: 5, 3, 7
    cout << "Massimo: " << triplaInt.trovaMassimo() << endl; // Output: Massimo: 7
    cout << "Minimo: " << triplaInt.trovaMinimo() << endl;   // Output: Minimo: 3
    triplaInt.ordina();
    triplaInt.stampaTripla(); // Output: Tripla: 3, 5, 7

    Tripla<double> triplaDouble(2.3, 1.1, 3.5);
    triplaDouble.stampaTripla(); // Output: Tripla: 2.3, 1.1, 3.5
    cout << "Massimo: " << triplaDouble.trovaMassimo() << endl; // Output: Massimo: 3.5
    cout << "Minimo: " << triplaDouble.trovaMinimo() << endl;   // Output: Minimo: 1.1
    triplaDouble.ordina();
    triplaDouble.stampaTripla(); // Output: Tripla: 1.1, 2.3, 3.5

    return 0;
}
