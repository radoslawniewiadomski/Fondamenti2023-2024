#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    int* const p3 = &c;
    int* const p1 = &a;
    const int* p2 =&b;
    const int* p4 =&d;

    a++;b++;c++;d++;

     p2=p4;
     p1=p3;
    (*p2)++;
    (*p1)++;

    cout<<a<<b<<c<<d;
}
