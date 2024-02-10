#include <iostream>
using namespace std;

//funzione aggiunge 1 ad ogni elemento di //un array
void add1(int* a, int size)
{
//void add1(int a [], int size) {

    for (int* pi=a; pi<a+size; pi++)
        (*pi)+=1;
}

int main()
{

    int s[] = {1,2,3,4,5};
    add1(s,5);

    for (int i=0; i<5; i++)
        cout << s[i]<< ", ";
    return 0;

}
