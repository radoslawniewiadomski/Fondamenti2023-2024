#include <iostream>
#include <cmath>
using namespace std;

// restituisce true se e solo se n è numero primo
bool NumeroPrimo(int n) {
	int i=2, lim=(int)sqrt(n);
	bool primo = true;
	while (primo && (i <= lim)) {
		primo = !(n % i == 0);
		i++;
		}
	return(primo);
}

// restituisce la somma dei quadrati dei primi n numeri primi
long sommaquadratiprimi(int n) {
	int i=3, j=0, sommatoria=0;
	while (j <= n) {
		if (NumeroPrimo(i)) {
			sommatoria += i*i;
			j++;
		}
		i++;
	}
	return sommatoria;
}

// restituisce la somma dei cubi dei primi n numeri primi
long sommacubiprimi(int n) {
	int i=3, j=0, sommatoria=0;
	while (j <= n) {
		if (NumeroPrimo(i)) {
			sommatoria += i*i*i;
			j++;
		}
		i++;
	}
	return sommatoria;
}

int main() {
	int scelta, n;
	long(*vettpuntfunz[])(int) = {sommaquadratiprimi, sommacubiprimi};
	cout << "0 per calcolare la somma dei quadrati\n"
	     << "1 per calcolare la somma dei cubi\n";
	cin >> scelta;
	cout << "per quanti primi numeri primi?\n";
	cin >> n;
	cout << vettpuntfunz[scelta](n) << endl;
	return 0;
}



