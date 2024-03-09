#include <iostream>
using namespace std;

const int dim = 30;

struct oggetto{
    char nome[dim];
    double prezzo;
};

int main(){
    int num;
    cout << "Per favore, inserisci il numero di oggetti da inserire nell'inventario: " << endl;
    cin >> num;
    oggetto* object = new oggetto[num];
    if (object == NULL)
        return -1;
    for (oggetto* p = object; p < object+num;p++){
        cout << "Per favore, inserisci il nome dell'oggetto: " << endl;
        fflush(stdin);
        cin.getline(p->nome, dim,'\n');
        cout << "Per favore, inserisci il prezzo dell'oggetto: " << endl;
        cin >> p->prezzo;
    }
    cout << "Ecco il tuo inventario: " << endl;
    for (oggetto* p = object; p < object+num;p++){
        cout << "Nome oggetto: " << p->nome << endl;
        cout << "Prezzo oggetto: " << p->prezzo << endl;
    }
    delete [] object;
return 0;
}
