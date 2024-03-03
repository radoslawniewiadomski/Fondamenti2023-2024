#include <iostream>
using namespace std;

double inverso (int a) {
	return 1.0 / a;
}

double quadrato (int a) {
	return double(a * a);
}

double assoluto (int a) {
	return abs(a);
}

double somma(int *a, double (*f)(int)) {
    double s=0.0;
    for (int i = 0; i < 5; i++)
            s += (*f)(*(a+i));
	return s;
	}

int main() {
   int a [] = {1,-2,3,-4,5};
   double (*pf[3])(int) =  {inverso, quadrato,assoluto};

   for(int i=0;i<3;i++) cout << somma(a, pf[i]) << endl;
	return 0;
}
