#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
const int NUM_SQUADRE = 8;
const int PARTITE_PER_SQUADRA = NUM_SQUADRE - 1;

// Funzione per calcolare i punti di una squadra
int calcolaPunti(int risultati[][NUM_SQUADRE], int squadraIndex) {
    int punti = 0;
    for (int i = 0; i < NUM_SQUADRE; ++i) {
        if (i != squadraIndex) {
            if (risultati[squadraIndex][i] > risultati[i][squadraIndex]) punti+=3;
            else if (risultati[squadraIndex][i] == risultati[i][squadraIndex] ) punti += 1;
        }
    }
    return punti;
}

int main() {
    const char* squadre[NUM_SQUADRE] = {"Squadra 1", "Squadra 2", "Squadra 3", "Squadra 4", "Squadra 5", "Squadra 6", "Squadra 7", "Squadra 8"};
    int risultati[NUM_SQUADRE][NUM_SQUADRE] = {{0}};

    // Impostazione del seed per la generazione casuale
    srand(time(NULL));

    // Simulazione dei risultati delle partite
    for (int i = 0; i < NUM_SQUADRE; ++i) {
        for (int j = i + 1; j < NUM_SQUADRE; ++j) {
            risultati[i][j] = rand() % 5; // Genera un punteggio casuale da 0 a 4
            risultati[j][i] = rand() % 5;
            cout<< squadre[i] << squadre[j] << " : " <<  risultati[i][j]  << " : " << risultati[j][i] << endl;
        }
    }

    // Calcolo dei risultati finali
    int punti[NUM_SQUADRE] = {0};
    int retiFatte[NUM_SQUADRE] = {0};
    int retiSubite[NUM_SQUADRE] = {0};
    for (int i = 0; i < NUM_SQUADRE; ++i) {
        punti[i] = calcolaPunti(risultati, i);
        for (int j = 0; j < NUM_SQUADRE; ++j) {
            retiFatte[i] += risultati[i][j];
            retiSubite[i] += risultati[j][i];
        }
    }

    // Trova la squadra vincente
    int squadraVincenteIndex = 0;
    for (int i = 1; i < NUM_SQUADRE; ++i) {
        if (punti[i] > punti[squadraVincenteIndex] || (punti[i] == punti[squadraVincenteIndex] && retiFatte[i] - retiSubite[i] > retiFatte[squadraVincenteIndex] - retiSubite[squadraVincenteIndex])) {
            squadraVincenteIndex = i;
        }
    }

    // Output dei risultati finali
    cout << "Risultati Finali:" << endl;
   cout << "Squadra\t\tPunti\tReti Fatte\tReti Subite" << endl;
    for (int i = 0; i < NUM_SQUADRE; ++i) {
        cout << squadre[i] << "\t\t" << punti[i] << "\t" << retiFatte[i] << "\t\t" << retiSubite[i] << endl;
    }

    // Output della squadra vincente
    cout << "La squadra vincente e: " << squadre[squadraVincenteIndex] << endl;
    return 0;
}
