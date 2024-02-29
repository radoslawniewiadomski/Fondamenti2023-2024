#include <iostream>
#include <string>
using namespace std;
char *c;
char x[100];
int n;
void carica (char *z,int d){
  int j;
  char *k;
  k=z;
  for (j=0;j<d;j++)
    {cout << "inserisci il carattere \t";
     cin >> *z;
     cout << endl;
     z++;}
  cout << "stampa del vettore \t" << endl;
  for (j=0;j<d;j++) {
    cout << *k << "\t";
    k++;}
  cout << "---- fine carica ----"<<endl;
}
void conta (char *z, int d)
{
   int nc,nv;
   int j;
   nc=0;
   nv=0;
   for (j=0;j<d;j++){
      if (*z=='a')
         nv++;
      if (*z=='e')
        nv++;
      if (*z=='i')
        nv++;
      if (*z=='o')
        nv++;
      if (*z=='u')
         nv++;
      nc=d-nv;
      z++;}
  cout << "il numero delle vocali è:\t:" << nv << endl;
  cout << "il numero delle consonanti è:\t:" << nc << endl;
}
int main () {
  int k;
  cout << "inserisci il numero dei caratteri\n";
  cin >> n;
  c=x;
  carica(c,n);
  c=x;
  conta(c,n);
  cout << endl;
  return 0;
}
