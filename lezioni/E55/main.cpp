#include <iostream>
using namespace std;

bool a_maggiore_b(int *a, int *b)     {
    if (*a > *b) return true;
    return false;
    }

int main()
{
    int a = 30;
    int b = 20;

    int * pa=&a;
    int * pb=&b;
    cout<<a_maggiore_b(pa,pb);

}
