#include <iostream>
using namespace std;

const int dim = 3;

void righe_negative(int A[dim][dim], int* b[dim])
{
	for (int** parr = b; parr < (b + dim); parr++)
		*parr = NULL;

	int somma = 0; int** pb = b;
	for (int* p = &A[0][0]; p < &A[0][0] + (dim * dim); p += dim) {
		for (int* q = p; q < (p + dim); q++)
			somma += *q;
		if (somma < 0) {
			*pb = p;
			pb++;
		}
		somma = 0;
	}
}


int main()
{
	int matrice[dim][dim];
	int* prighe[dim];

	cout << "Inserire gli elementi di una matrice A (" << dim << " x " << dim << ")" << endl;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			cout << "Elemento A[" << i << "][" << j << "]: ";
			cin >> matrice[i][j];
		}
	cout << endl;

	righe_negative(matrice, prighe);

	cout << "Righe con somma negativa:" << endl;
	int k = 0;
	while (prighe[k] != NULL && k < dim) {
		for (int h = 0; h < dim; h++)
			cout << *prighe[k]++ << " ";
		cout << endl;
		k++;
	}
	if (k == 0) cout << "Nessuna";
	cout << endl;



	return 0;
}
