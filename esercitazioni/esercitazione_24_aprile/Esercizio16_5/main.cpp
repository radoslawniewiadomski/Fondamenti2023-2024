#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Classe Pixel per rappresentare un colore RGB
class Pixel
{
private:
    int rosso;
    int verde;
    int blu;

public:
    Pixel();
    Pixel(int r, int g, int b);

    // Metodi per ottenere i valori dei colori
    int getRosso() const;
    int getVerde() const;
    int getBlu() const;

    // Operatore di moltiplicazione per uno scalare
    Pixel operator*(double scala) const;
};

Pixel::Pixel() : rosso(0), verde(0), blu(0) {}

Pixel::Pixel(int r, int g, int b) : rosso(r), verde(g), blu(b) {}

int Pixel::getRosso() const
{
    return rosso;
}

int Pixel::getVerde() const
{
    return verde;
}

int Pixel::getBlu() const
{
    return blu;
}

Pixel::Pixel(int r = 0, int g = 0, int b = 0);

Pixel Pixel::operator*(double scala) const
{
    int r = (int)(rosso * scala);
    int g = (int)(verde * scala);
    int b = (int)(blu * scala);
    return Pixel(r, g, b);
}

// Template di classe per una matrice di elementi generici
template<typename T>
class Matrice
{
private:
    int righe;
    int colonne;
    T** dati;

public:
    Matrice(int r, int c);
    ~Matrice();

    // Metodo per accedere e modificare gli elementi della matrice
    T& operator()(int riga, int colonna);

    // Metodo per ottenere il numero di righe della matrice
    int getRighe() const;
    // Metodo per ottenere il numero di righe della matrice
    int getColonne() const;

    void inserisciElemento(int riga, int colonna, const T& elemento);

    // Metodo per moltiplicare la matrice per uno scalare
    Matrice<T> operator*(double scala) const;

    // Metodo per ottenere un elemento specifico della matrice
    T getElemento(int riga, int colonna) const;
};

template<typename T>
Matrice<T>::Matrice(int r, int c) : righe(r), colonne(c)
{
    dati = new T*[righe];
    for (int i = 0; i < righe; ++i)
    {
        dati[i] = new T[colonne];
    }
}

template<typename T>
Matrice<T>::~Matrice()
{
    for (int i = 0; i < righe; ++i)
    {
        delete[] dati[i];
    }
    delete[] dati;
}

template<typename T>
int Matrice<T>::getRighe() const
{
    return righe;
}

template<typename T>
int Matrice<T>::getColonne() const
{
    return colonne;
}

template<typename T>
void Matrice<T>::inserisciElemento(int riga, int colonna, const T& elemento)
{
    dati[riga][colonna] = elemento;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(double scala) const
{
    Matrice<T> risultato(righe, colonne);

    for (int i = 0; i < righe; ++i)
    {
        for (int j = 0; j < colonne; ++j)
        {
            risultato.inserisciElemento(i,j,dati[i][j] * scala);
        }
    }

    return risultato;
}

template<typename T>
T Matrice<T>::getElemento(int riga, int colonna) const
{
    return dati[riga][colonna];
}

int main()
{
    // Inizializzazione del generatore di numeri casuali
    srand(time(nullptr));

    // Creazione di un'istanza di matrice di pixel 5x5
    Matrice<Pixel> matricePixel(5, 5);

    // Riempimento della matrice con pixel di colori casuali
    for (int i = 0; i < matricePixel.getRighe(); ++i)
    {
        for (int j = 0; j < matricePixel.getColonne(); ++j)
        {
            int rosso = rand() % 256; // Genera un numero casuale tra 0 e 255 per il rosso
            int verde = rand() % 256; // Genera un numero casuale tra 0 e 255 per il verde
            int blu = rand() % 256; // Genera un numero casuale tra 0 e 255 per il blu
            matricePixel.inserisciElemento(i,j,Pixel(rosso, verde, blu));
        }
    }


    // Moltiplicazione della matrice di pixel per uno scalare
    double scala = 1.5;
    Matrice<Pixel> matriceMoltiplicata = matricePixel * scala;

    // Stampare la matrice moltiplicata
    for (int i = 0; i < matriceMoltiplicata.getRighe(); ++i)
    {
        for (int j = 0; j < matriceMoltiplicata.getColonne(); ++j)
        {
            cout << "(" << matriceMoltiplicata.getElemento(i, j).getRosso() << ", "
                 << matriceMoltiplicata.getElemento(i, j).getVerde() << ", "
                 << matriceMoltiplicata.getElemento(i, j).getBlu() << ") ";
        }
        cout << endl;
    }


    cout << endl;
    cout << endl;
    cout << endl;

    // Creazione di un'istanza di matrice di interi 4x4
    Matrice<int> matriceInteri(4, 4);

    // Riempimento della matrice di interi con valori casuali
    for (int i = 0; i < matriceInteri.getRighe(); ++i)
    {
        for (int j = 0; j < matriceInteri.getColonne(); ++j)
        {
            int valore = rand() % 100; // Genera un numero casuale tra 0 e 99
            matriceInteri.inserisciElemento(i,j,valore);
        }
    }


    cout << endl;
    // Stampare la matrice moltiplicata
    for (int i = 0; i < matriceInteri.getRighe(); ++i)
    {
        for (int j = 0; j < matriceInteri.getColonne(); ++j)
        {
            cout << matriceInteri.getElemento(i, j)  <<  ", ";
        }
        cout << endl;
    }

    cout << endl;
    // Moltiplicazione della matrice di pixel per uno scalare
    Matrice<int> matriceIntMoltiplicata = matriceInteri * scala;

    // Stampare la matrice moltiplicata
    for (int i = 0; i < matriceIntMoltiplicata.getRighe(); ++i)
    {
        for (int j = 0; j < matriceIntMoltiplicata.getColonne(); ++j)
        {
            cout << matriceIntMoltiplicata.getElemento(i, j)  <<  ", ";
        }
        cout << endl;
    }

    return 0;
}
