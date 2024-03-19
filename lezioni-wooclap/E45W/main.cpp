#include <iostream>

using namespace std;


template <typename T>
T f1 (T x)
{
    return 4.0/x;
}

int main()
{
    cout << f1(3) << endl;
    return 0;
}
