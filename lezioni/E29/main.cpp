#include <iostream>
using namespace std;


double media (int a, int b) {
	return (a + b) / 2.0;
}

int main() {
	double (*pf)(int, int);
	pf = media;	// inizializzazione
	int x, y;
	cout << "Inserire due numeri: ";
	cin >> x >> y;
	double m = (*pf)(x, y); // chiamata
	cout << "Media = " << m << endl;
	return 0;
}
