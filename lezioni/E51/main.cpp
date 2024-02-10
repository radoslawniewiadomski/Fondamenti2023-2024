#include <iostream>
using namespace std;

struct Impiegato
{
    char nome[32];
    char cognome[32];
};


template <typename T>
void BubbleSort (T v[], int n)
{
    int i, j;
    T tmp;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
            {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
}


int main()
{
    int a[5] = {3, 2, 6, 1, 4};
    Impiegato imp[2] = {{"Mario","Rossi"},{"Paola","Bianchi"}};

    BubbleSort(a, 5);		// OK!
    BubbleSort(imp, 2);  	// ERRORE!   L’operatore > non è definito per le strutture!

    for (int i=0; i<2; i++)
        cout<<a[i]<<", ";

    return 0;

}
