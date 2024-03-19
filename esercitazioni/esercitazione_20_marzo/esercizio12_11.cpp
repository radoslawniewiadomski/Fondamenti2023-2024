#include <iostream>
#include <cstring>
using namespace std;

bool pal(char const *s, int cmin, int cmax) {
	if (cmin == cmax) return true; // lunghezza dispari
	if (cmin == cmax-1) {         // lunghezza pari
		if (*(s+cmin) == *(s+cmax)) return true;
		else return false;
	}
	if (*(s+cmin) == *(s+cmax)) return pal(s, cmin+1, cmax-1);
	else return false;
}

bool palindroma(char const *s) {
	if(pal(s, 0, strlen(s)-1)) return true;
	else return false;
}

int main() {
	char stringa[100];
	cin >> stringa;
	if (palindroma(stringa)) cout <<"Palindroma";
	else cout <<"NON Palindroma";
}
