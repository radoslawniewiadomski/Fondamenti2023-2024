#include <iostream>
using namespace std;
int main()
{
  int b[3] = {1, 4, 7};
  int* p = b;
  int *q = p+2;
   cout <<*p<<", "<<*q<<endl;
   cout <<q-p;
   return 0;
}
