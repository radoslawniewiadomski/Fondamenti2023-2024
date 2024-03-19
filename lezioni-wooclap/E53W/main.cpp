#include <iostream>
using namespace std;

template <typename W, typename S>
S f2 (W x, S y)
{
    if( x > y) return 1.2;
    return 0.1;
}
int main()
{
    double d1=4.2;
    int d2=4.8;
    cout << f2(d1,d2) << endl;
    return 0;
}
