#include <iostream>
using namespace std;

double somma(double x, double y)
{
    return x + y;
}
double differenza (double x, double y)
{
    return x - y;
}
double prodotto (double x, double y)
{
    return x * y;
}
double rapporto (double x, double y)
{
    if (y != 0.0) return x / y;
    else return 0.0;
}

int main()
{
    //semplice calcolatrice
    const int dim = 4;
    char operatori[dim] = {'+', '-', '*', '/'};
    double (*pf[dim])(double, double) =  {somma, differenza, prodotto, rapporto};
    double op1, op2, res;
    char op;

    cin >> op1 >> op >> op2;
    for (int i = 0; i < dim; i++)
        if (op == operatori[i])
            res = (*pf[i])(op1, op2);
    cout << op1 << op << op2 << " = " << res;
    cout << endl;
    return 0;
}

