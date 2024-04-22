#include <iostream>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()

//versione 2
//#include <iomanip>

using namespace std;

template<typename T, int n>
class Vettore
{
    T dati[n];
public:
    Vettore();
    void inserisciCasuale();
    void stampa();
};

template<typename T, int n>
Vettore<T,n>::Vettore(){
    //cout<<"costruttore";
}

template<typename T, int n>
void Vettore<T,n>::inserisciCasuale()
{
    // Inizializzazione casuale dei dati
    for (int i = 0; i < n; ++i)  dati[i] = rand() ;
}

template<typename T, int n>
void Vettore<T,n>::stampa()
{
    for (int i = 0; i < n; i++)
        cout << dati[i] << " ";

        //versione 2
        //cout << fixed << setprecision(2) << dati[i] << " ";

    cout << endl;
}

int main()
{
    srand(time(0));
    Vettore<double, 5> v1; // Vettore di 5 double
    v1.inserisciCasuale(); // Inserimento casuale di numeri nel vettore
    v1.stampa(); // Stampa il vettore di 5 double

    Vettore<int, 10> v2; // Vettore di 10 int
    v2.inserisciCasuale(); // Inserimento casuale di numeri nel vettore
    v2.stampa(); // Stampa il vettore di 10 int

    return 0;
}
