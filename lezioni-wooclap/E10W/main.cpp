#include <iostream>
using namespace std;
int main()
{
    double z=0.5;
    double y=0.5;
    double* p1=&z;
    double* p2=&y;

    cout <<  p1 << ", "  << p2 << endl;
    p2=p1;
    z+=1.0;

    cout << *p1 << ", " << *p2 << endl;
    return 0;
}
