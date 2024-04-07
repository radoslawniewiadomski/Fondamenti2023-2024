#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Studente {
    string nome;
    string cognome;
    int voto;
    ifstream* file; // Puntatore a oggetto ifstream per il file

public:
    // Costruttore con file
    Studente(ifstream& file);
    // Distruttore
    ~Studente();
    // Metodo per stampare i dati dello studente
    void stampaDati() const;
};

// Implementazione del costruttore con file
Studente::Studente(ifstream& file) : file(&file) {
    if (file.is_open()) {
        // Leggiamo i dati dal file e li assegniamo agli attributi della classe
        getline(file, nome);
        getline(file, cognome);
        file >> voto;
        file.ignore(); // Ignoriamo il carattere di nuova linea residuo

        // Stampa messaggio di errore se la lettura del voto fallisce
        if (file.fail()) {
            cerr << "Errore nella lettura del voto." << endl;
        }
    } else {
        cerr << "Impossibile aprire il file." << endl;
    }
}

// Implementazione del distruttore
Studente::~Studente() {
    // Chiudiamo l'accesso al file nel distruttore
    file->close();
    cout << "Distruttore chiamato per lo studente " << nome << " " << cognome << endl;
}

// Implementazione del metodo per stampare i dati dello studente
void Studente::stampaDati() const {
    cout << "Nome: " << nome << endl;
    cout << "Cognome: " << cognome << endl;
    cout << "Voto: " << voto << endl;
}

int main() {
    // Apriamo il file per la lettura
    ifstream inputFile("d:\\studenti.txt");

    // Verifichiamo se il file è stato aperto correttamente
    if (!inputFile.is_open()) {
        cerr << "Impossibile aprire il file." << endl;
        return 1;
    }

    // Creiamo un oggetto Studente utilizzando il costruttore con file
    Studente studente (inputFile);

    // Stampiamo i dati dello studente
    studente.stampaDati();

    return 0;
}
