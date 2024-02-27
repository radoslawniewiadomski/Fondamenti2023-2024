#include <iostream>
using namespace std;

int a [5];

int main()
{

    a[0]=20;
    a[1]=22;
    a[2]=26;
    a[3]=28;
    a[4]=30;

    cout << a[2];

    //cout << *(a+2);
    cout << *a+2;

    return 0;
}
