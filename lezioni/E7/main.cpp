#include <iostream>
using namespace std;
struct t
{
    int x;
    float y;
    float z;
};

int main()
{
    int x = 10;
    t t1;
    int* px = &x;
    t* pt1 = &t1;

    cout<<px<<pt1<<endl;
    cout<<*px<<endl;

    px = pt1; //ERRORE!!!


    return 0;
}
