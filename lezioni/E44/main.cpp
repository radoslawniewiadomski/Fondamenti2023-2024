#include <iostream>
using namespace std;

template <typename T>

T abs(T x)
{
    if (x < 0) return -x;
    else return x;
}

int main()
{
    int a;
    double z;
    cout << "Inserire un numero intero: ";
    cin >> a;
    cout << "Inserire un numero reale: ";
    cin >> z;
    int r = abs(a);
    cout << "|" << a << "| = " << r << endl;
    double s = abs(z);
    cout << "|" << z << "| = " << s << endl;
    return 0;
}
