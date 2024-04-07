#include <iostream>
#include <cstring>
using namespace std;

class Impiegato {
private:
    char nome[32];
    char cognome[32];
public:
    Impiegato(const char* _nome, const char* _cognome);
   Impiegato();

    // Operatore ">" sovraccaricato per confrontare due impiegati in base al cognome
    bool operator>(const Impiegato& imp) const;

    void stampa() const;
};

Impiegato::Impiegato() {
    strcpy(nome, "N/D");
    strcpy(cognome, "N/D");

}

Impiegato::Impiegato(const char* _nome, const char* _cognome) {
    strcpy(nome, _nome);
    strcpy(cognome, _cognome);
}

bool Impiegato::operator>(const Impiegato& imp) const {
    if (strcmp(cognome, imp.cognome) > 0) return true;
     return false;
}

void Impiegato::stampa() const {
    cout << "Nome: " << nome << ", Cognome: " << cognome << endl;
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
    int a[5] = {3, 2, 6, 1, 4};
    Impiegato imp[3] = {{"Mario", "Rossi"}, {"Paola", "Bianchi"}, {"Riccardo", "Bianccardi"}};

    cout << "Prima di ordinare:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        imp[i].stampa();
    }

    BubbleSort<int>(a, 5);
    BubbleSort<Impiegato>(imp, 3);

    cout << "\nDopo l'ordinamento:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        imp[i].stampa();
    }

    return 0;
}
