#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3;
    float *ptr1, *ptr2, *ptr3;
    float **max;

    // Input dei tre numeri reali
    cout << "Inserisci tre numeri reali: ";
    cin >> num1 >> num2 >> num3;

    // Assegnamento dei puntatori ai numeri reali
    ptr1 = &num1;
    ptr2 = &num2;
    ptr3 = &num3;

    // Assegnamento del puntatore al massimo al primo numero
    max = &ptr1;

    // Trova il massimo tra i tre numeri utilizzando i puntatori a puntatori
    if (*ptr2 > **max) {
        max = &ptr2;
    }
    if (*ptr3 > **max) {
        max = &ptr3;
    }

    cout << "Il massimo tra i tre numeri e: " << **max << std::endl;
    return 0;
}
