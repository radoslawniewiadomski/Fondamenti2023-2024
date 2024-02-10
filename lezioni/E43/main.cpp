#include <iostream>

using namespace std;

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int min_rec(int v[], int i, int j)
{
    if (i == j) return v[i];
    else return min(v[i], min_rec(v, i+1, j));
}

int min_in_array(int v[], int n)
{
    return min_rec(v, 0, n-1);
}

int main()
{
    int a[10] = {1, 3, 8, 2, 5, 0, 4, 6, 9, 7};
    int m = min_in_array(a, 10);
    cout << "min = " << m << endl;
    return 0;
}
