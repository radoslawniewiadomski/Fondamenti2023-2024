#include <iostream>
using namespace std;

int main()
{
    int* a;

    for (int k = 0; k < 10000; k++)
    {
        a = new int[k];
        if (a == NULL)
        {
            cout << "Memory allocation failed." << endl;
            return -1;
        }
        for (int i = 0; i < k; i++) a[i] = i + 1;
        for (int j = 0; j < k; j++) cout << a[j] << ", ";
    }
    delete[] a;
    return 0;

}
