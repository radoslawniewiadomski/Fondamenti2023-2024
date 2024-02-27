#include <iostream>
using namespace std;
int main() {
   int a=1, b=2, c=3;

    int* p [3];
    p[0]=&a;
    p[1]=&b;
    p[2]=&c;

    int** q=p;

    **q+=100;
    **(q+1)+=100;

   for (int i=0; i<3;i++)
	cout << *(p[i])<< ", ";
}
