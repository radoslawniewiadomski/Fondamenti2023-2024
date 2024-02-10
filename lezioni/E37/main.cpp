#include <iostream>
using namespace std;


int main()
{
    int n;
    cout << "Inserire il numero di elementi: ";
    cin >> n;

    if (n <= 0) return -1;
    int* a = new int[n];

    if (a == 0) return -1;

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int j = 0; j < n - 1; j++)
        cout << a[j] << ", ";

    cout << a[n - 1] << endl;
    delete [] a;
    return 0;
}
