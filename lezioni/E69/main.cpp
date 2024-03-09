#include <iostream>
using namespace std;

int main() {
    // Allocazione iniziale di memoria per un array di 3 interi
    int* array = new int[3];

    // Inizializzazione dei valori dell'array
    for (int i = 0; i < 3; ++i) {
        array[i] = i * 10;
    }


    // Riallocazione di memoria per un array di 5 interi
    int* newArray = new int[5];

    // Copia dei valori dall'array originale al nuovo array
    for (int i = 0; i < 3; ++i) {
        newArray[i] = array[i];
    }

    // Deallocazione della memoria dell'array originale
    delete[] array;

    // Aggiunta di valori aggiuntivi al nuovo array
    for (int i = 3; i < 5; ++i) {
        newArray[i] = i * 10;
    }

    std::cout << "Valori del nuovo array dopo la riallocazione:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << newArray[i] << " ";
    }
    std::cout << std::endl;

    // Deallocazione della memoria del nuovo array
    delete[] newArray;

    return 0;
}
