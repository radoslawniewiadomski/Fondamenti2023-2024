#include <iostream>
using namespace std;

const char* nomi_mesi[12] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio",
                             "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre",
                             "Novembre", "Dicembre"
                            };

int main()
{

    // Iterazione attraverso l'array per stampare tutti i mesi
    for (int i = 0; i < 12; ++i) {
        cout << i + 1 << ". " << nomi_mesi[i] << endl;
    }

    return 0;
}



