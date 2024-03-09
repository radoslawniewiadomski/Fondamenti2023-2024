#include <iostream>
using namespace std;

#include <cstring> // Per la funzione strcpy
int main() {
    char* nome = new char[6];
    strcpy(nome, "Maria");

    cout << "Nome: " << nome << endl;

    // Riallocazione di memoria perche la persona ha anche un secondo nome
    char*  doppionome = new char[12]; // Allocazione di nuova memoria

    strcpy(doppionome, nome);
    delete[] nome;

    strcat(doppionome, "Carla");
    cout << "Nuovo nome: " << doppionome << endl;

    delete[] doppionome;

    return 0;
}
