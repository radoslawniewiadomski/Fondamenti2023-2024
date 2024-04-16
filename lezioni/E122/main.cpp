
#include "..\Impiegato.h"
#include "..\Film.h"
#include "..\E121\Punto.h"

#include <iostream>
using namespace std;


template<typename T>
void swap2(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void BubbleSort (T v[], int n) {
	int i, j;
	T tmp;
	for (i = n - 1; i > 0; i--)
		for (j = 0; j < i; j++)
      		if (v[j] > v[j+1]) {
				tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
	}
}


int main() {
    //int a[2] = {{3, 2}, {6, 1}};
    Impiegato imp[3] = {{"Mario", "Rossi"}, {"Paola", "Bianchi"}, {"Riccardo", "Bianccardi"}};

     film filmArray[5] = {
        {"Matrix", 120, 1999},
        {"Inception", 148, 2010},
        {"Interstellar", 169, 2014},
        {"Shawshank", 142, 1993},
        {"Pulp", 154, 1994}
    };

    cout << "Prima di ordinare:" << endl;
    for (int i = 0; i < 5; ++i) {
        filmArray[i].stampaFilm();
    }

    BubbleSort<Impiegato>(imp, 3);
    BubbleSort<film>(filmArray, 5);

    cout << "\nDopo l'ordinamento:" << endl;

    for (int i = 0; i < 3; ++i) {
        imp[i].stampa();
    }

    for (int i = 0; i < 5; ++i) {
        filmArray[i].stampaFilm();
    }

    return 0;
}
