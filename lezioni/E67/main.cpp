#include <iostream>
using namespace std;

void add1(int a[][3]) {
//void add1(int **a) { //ERRORE
//void add1(int (*a)[3]) {

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] += 1;
}

int main() {
    int s[3][3] = {1,2,3,4,5,6,7,8,9};
    add1(s);
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cout << s[i][j]<< ", ";

    return 0;
}
