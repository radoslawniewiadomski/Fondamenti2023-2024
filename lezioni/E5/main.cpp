#include <iostream>

using namespace std;


int main()
{

    int x = 10;
    int* px = &x;

    cout << x << endl;// stampa 10

    cout << px << endl;// stampa 0x000003A6

    cout << &px << endl;// stampa 0x000016D8

    return 0;
}
