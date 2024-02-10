#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

template <typename W, typename S>
S f2 (W x)
{
    int z = x/2;
    return z;
}

int main()
{
    double d1=3.9;
    cout << f2(d1) << endl; //ERRORE
    return 0;
}
