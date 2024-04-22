#include <iostream>
using namespace std;

// Definizione delle funzioni
int somma(int a, int b) {
    return a + b;
}

int sottrazione(int a, int b) {
    return a - b;
}

int moltiplicazione(int a, int b) {
    return a * b;
}

template<typename T, T Funzione(T, T)>
class Calcolatrice {
    T x;
    T y;
public:
    Calcolatrice(T val1, T val2);
    T eseguiOperazione();
};

template<typename T, T Funzione(T, T)>

Calcolatrice<T, Funzione>::Calcolatrice(T val1, T val2) : x(val1), y(val2) {}

template<typename T, T Funzione(T, T)>

T Calcolatrice<T, Funzione>::eseguiOperazione() {
    return Funzione(x, y);
}


int main() {
    // Creazione di istanze di Calcolatrice specializzate per diverse operazioni
    Calcolatrice<int, somma> calcSomma(5, 3);
    Calcolatrice<int, sottrazione> calcSottrazione(5, 3);
    Calcolatrice<int, moltiplicazione> calcMoltiplicazione(5, 3);

    // Esempio di utilizzo
    int risultatoSomma = calcSomma.eseguiOperazione();
    cout << "Il risultato della sommae: " << risultatoSomma << endl;

    int risultatoSottrazione = calcSottrazione.eseguiOperazione();
    cout << "Il risultato della sottrazione e: " << risultatoSottrazione << endl;

    int risultatoMoltiplicazione = calcMoltiplicazione.eseguiOperazione();
    cout << "Il risultato della moltiplicazione e: " << risultatoMoltiplicazione << endl;

    return 0;
}
