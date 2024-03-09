#include <iostream>
using namespace std;

int maggiore(int a, int b)
{
	return a > b;
}

int minore(int a, int b)
{
	return a < b;
}

void scambia(int& a, int& b) 
{
	int t = a;
	a = b;
	b = t;
}

void bubble_sort(int v[], int n, int (*pf)(int, int))
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (!(*pf)(v[j], v[j + 1]))
				scambia(v[j], v[j + 1]);
}

int main() 
{
	const int dim = 10;
	int w[dim];
	cout << "Inserire " << dim << " numeri interi: " << endl;
	for (int i = 0; i < dim; i++) {
		cout << "Valore " << i + 1 << ": ";
		cin >> w[i];
	}
	int scelta = 0;
	do {
		cout << "Come si vogliono ordinare i dati? " << endl;
		cout << "1 - In senso crescente" << endl;
		cout << "2 - In senso decrescente" << endl;
		cin >> scelta;
		switch (scelta) {
		case 1:
			bubble_sort(w, dim, minore);
			break;
		case 2:
			bubble_sort(w, dim, maggiore);
			break;
		default:
			cout << "Errore: scegliere 1 o 2" << endl;
		}
	} while (scelta != 1 && scelta != 2);
	cout << "Dati ordinati: " << endl << "{ ";
	for (int i = 0; i < dim - 1; i++)
		cout << w[i] << ", ";
	cout << w[dim - 1] << " } " << endl;
	return 0;
}
