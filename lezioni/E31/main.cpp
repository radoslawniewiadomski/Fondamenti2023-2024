#include <iostream>
using namespace std;

double inverso (int a)
{
    return 1.0 / a;
}

double quadrato (int a)
{
    return double(a * a);
}

double somma(int n, double (*f)(int))
{
    double s = 0.0;
    for (int i = 1; i <= n; i++)
        s += (*f)(i);
    return s;
}

int main()
{
    cout << somma(5, inverso) << endl;
    cout << somma(5, quadrato) << endl;
    return 0;
}


/*
double somma_inverso (int n)
{
    double s = 0.0;
    for (int i = 1; i <= n; i++)
        s += 1.0 /(i);
    return s;
}
double somma_quadrato (int n)
{
    double s = 0.0;
    for (int i = 1; i <= n; i++)
        s+= i*i;
    return s;
}

int main()
{
    cout<<somma_inverso(5)<< endl;
    cout<<somma_quadrato(5)<< endl;
    return 0;
}
 */
