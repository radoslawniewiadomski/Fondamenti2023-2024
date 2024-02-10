#include <iostream>
using namespace std;

int *secondo_elemento (int a[]){
  int *b = a;
  b++;
  return b;
}

int main(){
    int a []={1,2,4};
    cout << *secondo_elemento(a);
    return 0;
}
