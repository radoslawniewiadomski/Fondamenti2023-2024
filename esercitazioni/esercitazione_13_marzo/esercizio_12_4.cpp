#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
int contaDistinti(T a[], int n) {
	int c = 1; int i, j;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (a[j] == a[i])
				break;
		if (i == j)
			c++;
	}
	return c;
}

int main()
{
	const int dim = 10;
	int v[dim] = { 0 };
	double w[dim] = { 0.0 };
	char s[dim] = "";

	char c = 'n';
	do {
		cout << "Inserire i valori per un array di " << dim << " numeri interi" << endl;
		for (int i = 0; i < dim; i++) {
			cout << "Inserire il valore in posizione " << i + 1 << ": ";
			cin >> v[i];
		}
		cout << "Inserire i valori per un array di " << dim << " numeri reali" << endl;
		for (int i = 0; i < dim; i++) {
			cout << "Inserire il valore in posizione " << i + 1 << ": ";
			cin >> w[i];
		}
		cout << "Inserire una stringa di " << dim << " caratteri" << endl;
		cin >> s;
		int l = strlen(s);
		cout << "Numero di elementi distinti: " << endl;
		cout << "Per l'array di numeri interi: " << contaDistinti(v, dim) << endl;
		cout << "Per l'array di numeri reali: " << contaDistinti(w, dim) << endl;
		cout << "Per la stringa di caratteri: " << contaDistinti(s, l) << endl;

		do {
			cout << "Desideri continuare (s/n)? ";
			cin >> c;
			if (c != 's' && c != 'n')
				cout << "Inserire s oppure n" << endl;
		} while (c != 's' && c != 'n');
	} while (c == 's');

	return 0;
}
