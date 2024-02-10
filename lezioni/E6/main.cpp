#include <iostream>

using namespace std;

int main()
{


    int* px; //ERRORE!!!
    *px = 1;

    cout<<"Resultati";
    cout<<"px" << *px;

    return 0;
}
