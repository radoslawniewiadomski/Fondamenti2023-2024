#include <iostream>
using namespace std;

int* a_maggiore_b(int *a, int *b)     {
    if (*a > *b) return a;
    return b;
    }

int main() {
    int a = 30;
    int b = 20;

    int * pa=&a;
    int * pb=&b;
    int *maggiore = a_maggiore_b(pa,pb);
    cout <<"*maggiore="<<*maggiore<<", indirizzo di maggiore = "<< maggiore;
}
