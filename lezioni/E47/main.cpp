#include <iostream>
using namespace std;


template <typename W, typename S>
S f2 (W x) {
  int z = x/2;
  return z;
}

/*
int main() {
 double d1=3.9;
 int d2 = f2(d1) ; //ERRORE
 return 0;
}
*/

//soluzione del problema

int main() {
 double d1=3.9;
 double d2 = f2<int,double>(d1); //esplicitamente indico dei tipi
 cout<<d2;
 return 0;
}
