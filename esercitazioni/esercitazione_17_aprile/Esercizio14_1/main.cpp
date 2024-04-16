#include <iostream>
#include <cmath>

using namespace std;

class Punto2D {
private:
    double x;
    double y;

public:
    // Costruttori
    Punto2D();
    Punto2D(double x_, double y_);
    Punto2D(const Punto2D &other);

    // Distruttore
    ~Punto2D();

    // Selettori
    double getX() const;
    double getY() const;

    // Modificatori
    void setX(double x_);
    void setY(double y_);

    // Operatori unari
    Punto2D operator-() const;
    Punto2D& operator++(); // Incremento prefisso
    Punto2D operator++(int); // Incremento postfisso
    Punto2D& operator--(); // Decremento prefisso
    Punto2D operator--(int); // Decremento postfisso

    // Operatori aritmetici
    Punto2D operator+(const Punto2D& other) const;
    Punto2D operator-(const Punto2D& other) const;
    Punto2D operator*(double scalar) const;

    // Operatore di assegnamento
    Punto2D& operator=(const Punto2D& other);

    // Operatore di uguaglianza
    bool operator==(const Punto2D& other) const;

    // Operatori di inserimento ed estrazione
    friend ostream& operator<<(ostream& out, const Punto2D& punto);
    friend istream& operator>>(istream& in, Punto2D& punto);

    // Funzione esterna amica per il calcolo della distanza tra due punti
    friend double distanza(const Punto2D& p1, const Punto2D& p2);
};

// Definizione dei metodi

// Costruttore di default
Punto2D::Punto2D() : x(0), y(0) {}

// Costruttore con parametri
Punto2D::Punto2D(double x_, double y_) : x(x_), y(y_) {}

// Costruttore di copia
Punto2D::Punto2D(const Punto2D &other) : x(other.x), y(other.y) {}

// Distruttore
Punto2D::~Punto2D() {}

// Selettori
double Punto2D::getX() const { return x; }
double Punto2D::getY() const { return y; }

// Modificatori
void Punto2D::setX(double x_) { x = x_; }
void Punto2D::setY(double y_) { y = y_; }

// Operatori unari
Punto2D Punto2D::operator-() const {
    return Punto2D(-x, -y);
}

Punto2D& Punto2D::operator++() { // Incremento prefisso
    x++;
    y++;
    return *this;
}

Punto2D Punto2D::operator++(int) { // Incremento postfisso
    Punto2D temp(*this);
    ++(*this);
    return temp;
}

Punto2D& Punto2D::operator--() { // Decremento prefisso
    x--;
    y--;
    return *this;
}

Punto2D Punto2D::operator--(int) { // Decremento postfisso
    Punto2D temp(*this);
    --(*this);
    return temp;
}

// Operatori aritmetici
Punto2D Punto2D::operator+(const Punto2D& other) const {
    return Punto2D(x + other.x, y + other.y);
}

Punto2D Punto2D::operator-(const Punto2D& other) const {
    return Punto2D(x - other.x, y - other.y);
}

Punto2D Punto2D::operator*(double scalar) const {
    return Punto2D(x * scalar, y * scalar);
}

// Operatore di assegnamento
Punto2D& Punto2D::operator=(const Punto2D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Operatore di uguaglianza
bool Punto2D::operator==(const Punto2D& other) const {
    return (x == other.x && y == other.y);
}

// Operatori di inserimento ed estrazione
ostream& operator<<(ostream& out, const Punto2D& punto) {
    out << "(" << punto.x << ", " << punto.y << ")";
    return out;
}

istream& operator>>(istream& in, Punto2D& punto) {
    in >> punto.x >> punto.y;
    return in;
}

// Funzione esterna amica per il calcolo della distanza tra due punti
double distanza(const Punto2D& p1, const Punto2D& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Funzione main
int main() {
    Punto2D punto1, punto2;
    cout << "Inserisci le coordinate del primo punto (x y): ";
    cin >> punto1;
    cout << "Inserisci le coordinate del secondo punto (x y): ";
    cin >> punto2;

    cout << "Coordinate del primo punto: " << punto1 << endl;
    cout << "Coordinate del secondo punto: " << punto2 << endl;

    cout << "Somma dei punti: " << punto1 + punto2 << endl;
    cout << "Differenza dei punti: " << punto1 - punto2 << endl;
    cout << "Distanza tra i punti: " << distanza(punto1, punto2) << endl;

    return 0;
}

