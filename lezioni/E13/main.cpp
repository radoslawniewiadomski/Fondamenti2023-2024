#include <iostream>
using namespace std;

int main(){
    int a = 3;
    int* p1 = &a;
    int** p2 = &p1;
    cout << p1 <<", "<< p2<< endl;
    cout << *p1 <<", "<< *p2<< endl;

    p2=p1; //ERRORE
    return 0;
}
