#include <iostream>
using namespace std;


double somma(double x, double y){
  return x+y;
}
double differenza(double x, double y){
  return x-y;
}

int main()
{
    double (*pf) (double, double);
    pf = somma;

    double a,b;
    cin>>a>>b;

    if (a>b)
        pf = somma;
    else
        pf=differenza;

    cout << (*pf)(a,b);
}
