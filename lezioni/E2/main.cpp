#include <iostream>
using namespace std;
int main()
{
    int x = 1;
    int z = 1;

    int& y; //ERRORE

    x++;
    cout << x << endl;
    return 0;
}
