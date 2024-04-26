#include <cstdlib>
#include <ctime>
#include <iostream>

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

Pixel Pixel::operator*(double scala) const
{
    int r = static_cast<int>(rosso * scala);
    int g = static_cast<int>(verde * scala);
    int b = static_cast<int>(blu * scala);
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
    // Metodo per ottenere il numero di colonne della matrice
    int getColonne() const;

    // Metodo per moltiplicare la matrice per uno scalare
    Matrice<T> operator*(double scala) const;

    // Convolution
    Matrice<T> convolution(const Matrice<T>& filtro) const;
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
T& Matrice<T>::operator()(int riga, int colonna)
{
    return dati[riga][colonna];
}

template<typename T>
Matrice<T> Matrice<T>::operator*(double scala) const
{
    Matrice<T> risultato(righe, colonne);

    for (int i = 0; i < righe; ++i)
    {
        for (int j = 0; j < colonne; ++j)
        {
            risultato(i, j) = dati[i][j] * scala;
        }
    }

    return risultato;
}

template<typename T>
Matrice<T> Matrice<T>::convolution(const Matrice<T>& filtro) const
{
    Matrice<T> risultato(righe, colonne);

    for (int i = 0; i < righe; ++i)
    {
        for (int j = 0; j < colonne; ++j)
        {
            // Applica la convoluzione al pixel corrente
            for (int x = -1; x <= 1; ++x)
            {
                for (int y = -1; y <= 1; ++y)
                {
                    int newI = i + x;
                    int newJ = j + y;

                    if (newI >= 0 && newI < righe && newJ >= 0 && newJ < colonne)
                    {
                        // Somma i valori dei pixel convoluti
                        risultato(i, j) += filtro(x + 1, y + 1) * dati[newI][newJ];
                    }
                }
            }
        }
    }

    return risultato;
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
            matricePixel(i, j) = Pixel(rosso, verde, blu);
        }
    }
       cout << endl;

     // Stampare la matrice moltiplicata
    for (int i = 0; i < matricePixel.getRighe(); ++i)
    {
        for (int j = 0; j < matricePixel.getColonne(); ++j)
        {
            cout << "(" << matricePixel(i, j).getRosso() << ", "
                 << matricePixel(i, j).getVerde() << ", "
                 << matricePixel(i, j).getBlu() << ") ";
        }
        cout << endl;
    }

    // Moltiplicazione della matrice di pixel per uno scalare
    double scala = 1.5;
    Matrice<Pixel> matriceMoltiplicata = matricePixel * scala;
       cout << endl;
    // Stampare la matrice moltiplicata
    for (int i = 0; i < matriceMoltiplicata.getRighe(); ++i)
    {
        for (int j = 0; j < matriceMoltiplicata.getColonne(); ++j)
        {
            cout << "(" << matriceMoltiplicata(i, j).getRosso() << ", "
                 << matriceMoltiplicata(i, j).getVerde() << ", "
                 << matriceMoltiplicata(i, j).getBlu() << ") ";
        }
        cout << endl;
    }

    return 0;
}
