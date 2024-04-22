#include <iostream>
using namespace std;

template<typename T>
T somma(T a, T b) {
    return a + b;
}

template<typename T>
T sottrazione(T a, T b) {
    return a - b;
}

template<typename T>
T moltiplicazione(T a, T b) {
    return a * b;
}

// Definizione del template di classe per la Calcolatrice
template<typename T, T Funzione(T, T)>
class Calcolatrice {
    T x;
    T y;
public:
    Calcolatrice(T val1, T val2);
    T eseguiOperazione();
};

// Definizione del costruttore della classe Calcolatrice
template<typename T, T Funzione(T, T)>
Calcolatrice<T, Funzione>::Calcolatrice(T val1, T val2) : x(val1), y(val2) {}

// Definizione del metodo eseguiOperazione della classe Calcolatrice
template<typename T, T Funzione(T, T)>
T Calcolatrice<T, Funzione>::eseguiOperazione() {
    return Funzione(x, y);
}

int main() {
    // Creazione di istanze di Calcolatrice specializzate per diverse operazioni
    Calcolatrice<int, somma> calcSomma(5, 3);
    Calcolatrice<int, sottrazione> calcSottrazione(5, 3);
    Calcolatrice<double, moltiplicazione> calcMoltiplicazione(5.5, 3.3);

    // Esempio di utilizzo
    int risultatoSomma = calcSomma.eseguiOperazione();
    cout << "Il risultato della somma e: " << risultatoSomma << endl;

    int risultatoSottrazione = calcSottrazione.eseguiOperazione();
    cout << "Il risultato della sottrazione e: " << risultatoSottrazione << endl;

    double risultatoMoltiplicazione = calcMoltiplicazione.eseguiOperazione();
    cout << "Il risultato della moltiplicazione e: " << risultatoMoltiplicazione << endl;

    return 0;
}
