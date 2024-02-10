#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s1[256];
    char s2[256];
    char* ps3;
    cout << "Inserire due stringhe: ";
    cin >> s1 >> s2;
    int dim1 = strlen(s1);
    int dim2 = strlen(s2);
    ps3 = new char[dim1+dim2+1]; //allocazione
    if (ps3 == 0) return -1;
    strcpy(ps3, s1);
    strcat(ps3, s2);
    cout << "Stringa concatenata: " << ps3 << endl;

    delete[] ps3;    //deallocazione
    return 0;
}
