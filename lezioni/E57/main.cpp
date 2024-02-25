#include <iostream>
using namespace std;

int* maggiore_indirizzo(int *a, int *b)     {
    if (a > b) return a;
    return b;
    }

int main() {
    int a = 20;
    int b = 30;

    int * pa=&a; cout<<pa<<endl;
    int * pb=&b; cout<<pb<<endl;
    int *maggiore = maggiore_indirizzo(pa,pb);
    cout <<" il valore puntato da puntatore maggiore="<<*maggiore<<", l'indirizzo maggiore = "<< maggiore;
}
