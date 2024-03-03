#include <iostream>

using namespace std;

struct film {
    int id;
    char titolo[50];
    int durata;
    int anno;
};


int main()
{
    film (*a)[3];

    (*a)[1].id=1;

    return 0;
}
