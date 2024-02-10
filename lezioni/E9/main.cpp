
#include <iostream>
using namespace std;

int main()
{
    double z=0.5;

    double* pz=NULL;
    pz=&z;
    double* pz2=NULL;

    cout <<  pz << ", "  << pz2 << endl;

    pz2=pz;
    cout <<  pz << ", "  << pz2 << endl;

    cout << *pz << ", " << *pz2 << endl;

    return 0;
}

