#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    int& y = x;	// y è un reference x
    x++;
    cout << x << endl;	// stampa 2
    y++;
    cout << y << endl;	// stampa 3
    return 0;
}

