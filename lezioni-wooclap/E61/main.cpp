#include <iostream>
using namespace std;

int *f1 (int *a){
  return a;
}
int *f2(int *b){
    b+=4;
  return b;
}
int *f3(int *c){
    c+=2;
    return c;
 }

int main() {
    int* (*pf) (int*) = NULL;
    int x [] = {1,2,3,4,5};

   int a,b;
    cin>>a>>b;

    if (a>b) pf=f1;
    if (a<b) pf=f2;
    if (a==b) pf=f3;

    cout << (*pf)(x);
    return 0;
}
