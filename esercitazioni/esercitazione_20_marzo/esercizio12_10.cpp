#include <iostream>
#include <ctime>
using namespace std;


bool MatriceSimmetrica(int mat[][2], int rig, int col) {
	for (int i=0; i<rig; i++)
		for (int j=0; j<col; j++)
			if (*(*(mat + i) + j) != *(*(mat + j) + i))
                return false;
    return true;
}

void RiempiMatrice(int mat[][2], int rig, int col) {
	srand(time(NULL));
	for (int i=0; i<rig; i++)
		for (int j=0; j<col; j++) *(*(mat + i) + j) = rand() % 3;
}

void StampaMatrice(int mat[][2], int rig, int col) {
	for (int i=0; i<rig; i++) {
		for (int j=0; j<col; j++) cout << *(*(mat + i) + j) << ' ';
		cout << endl;
	}
}

int main() {
    int matrice[2][2];
	RiempiMatrice(matrice,2,2);
	StampaMatrice(matrice,2,2);
	if (MatriceSimmetrica(matrice, 2, 2)) {
		cout << "Simmetrica" << endl;
	}
	else {
		cout << "Asimmetrica" << endl;
	}
return 0;
}
