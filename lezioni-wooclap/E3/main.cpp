#include <iostream>
using namespace std;
int main()
{
    int a=3;
    int c=7;
    int& b=a;
    b=c;

    cout << a <<", " << b;
}
