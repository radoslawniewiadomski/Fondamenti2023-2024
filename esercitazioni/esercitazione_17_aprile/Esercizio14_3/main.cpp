#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Punto3D {
private:
    double x;
    double y;
    double z;

public:
    // Costruttori
    Punto3D();
    Punto3D(double x_, double y_, double z_);
    Punto3D(const Punto3D &other);

    // Distruttore
    ~Punto3D();

    // Selettori
    double getX() const;
    double getY() const;
    double getZ() const;

    // Modificatori
    void setX(double x_);
    void setY(double y_);
    void setZ(double z_);

    // Operatori unari
    Punto3D operator-() const;
    Punto3D& operator++(); // Incremento prefisso
    Punto3D operator++(int); // Incremento postfisso
    Punto3D& operator--(); // Decremento prefisso
    Punto3D operator--(int); // Decremento postfisso

    // Operatori aritmetici
    Punto3D operator+(const Punto3D& other) const;
    Punto3D operator-(const Punto3D& other) const;
    Punto3D operator*(double scalar) const;

    // Operatore di assegnamento
    Punto3D& operator=(const Punto3D& other);

    // Operatore di uguaglianza
    bool operator==(const Punto3D& other) const;

    // Operatori di inserimento ed estrazione
    friend ostream& operator<<(ostream& out, const Punto3D& punto);
    friend istream& operator>>(istream& in, Punto3D& punto);

    // Funzione esterna amica per il calcolo della distanza tra due punti
    friend double distanza(const Punto3D& p1, const Punto3D& p2);
};

// Definizione dei metodi

// Costruttore di default
Punto3D::Punto3D() : x(0), y(0), z(0) {}

// Costruttore con parametri
Punto3D::Punto3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

// Costruttore di copia
Punto3D::Punto3D(const Punto3D &other) : x(other.x), y(other.y), z(other.z) {}

// Distruttore
Punto3D::~Punto3D() {}

// Selettori
double Punto3D::getX() const { return x; }
double Punto3D::getY() const { return y; }
double Punto3D::getZ() const { return z; }

// Modificatori
void Punto3D::setX(double x_) { x = x_; }
void Punto3D::setY(double y_) { y = y_; }
void Punto3D::setZ(double z_) { z = z_; }

// Operatori unari
Punto3D Punto3D::operator-() const {
    return Punto3D(-x, -y, -z);
}

Punto3D& Punto3D::operator++() { // Incremento prefisso
    x++;
    y++;
    z++;
    return *this;
}

Punto3D Punto3D::operator++(int) { // Incremento postfisso
    Punto3D temp(*this);
    ++(*this);
    return temp;
}

Punto3D& Punto3D::operator--() { // Decremento prefisso
    x--;
    y--;
    z--;
    return *this;
}

Punto3D Punto3D::operator--(int) { // Decremento postfisso
    Punto3D temp(*this);
    --(*this);
    return temp;
}

// Operatori aritmetici
Punto3D Punto3D::operator+(const Punto3D& other) const {
    return Punto3D(x + other.x, y + other.y, z + other.z);
}

Punto3D Punto3D::operator-(const Punto3D& other) const {
    return Punto3D(x - other.x, y - other.y, z - other.z);
}

Punto3D Punto3D::operator*(double scalar) const {
    return Punto3D(x * scalar, y * scalar, z * scalar);
}

// Operatore di assegnamento
Punto3D& Punto3D::operator=(const Punto3D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

// Operatore di uguaglianza
bool Punto3D::operator==(const Punto3D& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

// Operatori di inserimento ed estrazione
ostream& operator<<(ostream& out, const Punto3D& punto) {
    out << "(" << punto.x << ", " << punto.y << ", " << punto.z << ")";
    return out;
}

istream& operator>>(istream& in, Punto3D& punto) {
    in >> punto.x >> punto.y >> punto.z;
    return in;
}

// Funzione esterna amica per il calcolo della distanza tra due punti
double distanza(const Punto3D& p1, const Punto3D& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}


int main() {
    ifstream fin("d:\\punti3D.txt");
    if (!fin) {
        cerr << "Impossibile aprire il file di input." << endl;
        return 1;
    }

    // Conta il numero di punti nel file
    int numPunti = 0;
    double tempX, tempY, tempZ;
    while (fin >> tempX >> tempY >> tempZ) {
        ++numPunti;
    }
    fin.clear(); // Resetta lo stato del file
    fin.seekg(0, ios::beg); // Riposiziona l'indicatore all'inizio del file

    // Allocazione dinamica dell'array di punti
    Punto3D* punti = new Punto3D[numPunti];

    // Lettura dei punti dal file e inserimento nell'array dinamico
    for (int i = 0; i < numPunti; ++i) {
        fin >> punti[i];
    }
    fin.close();

    // Calcolo della media della velocità con tecnica di finestra scorrevole
    const int finestra = 15;
    cout << "Velocita per ogni finestra di 15 punti:" << endl;
    for (int i = 0; i <= numPunti - finestra; ++i) {
        double sommaDistanze = 0.0;
        for (int j = 0; j < finestra - 1; ++j) {
            sommaDistanze += distanza(punti[i + j], punti[i + j + 1]);
        }
        double velocitaMedia = sommaDistanze / (finestra - 1);
        cout << "Finestra " << i + 1 << ": " << velocitaMedia << endl;
    }

    delete[] punti; // Dealloca l'array dinamico

    return 0;
}
