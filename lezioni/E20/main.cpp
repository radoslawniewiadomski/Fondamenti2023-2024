#include <iostream>
using namespace std;
int main()
{
   int b[3] = {8, 9, 10};
   int* p = b;

   cout <<"*p="<<*p<<", p= "<< p << "\n";

   p++;

   cout <<"*p="<<*p<<", p= "<< p << "\n";

   //b++; //ERRORE
   //cout <<"*b="<<*b<<", b= "<< b;

   return 0;
}
