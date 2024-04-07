#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
class Coppia {
    T primo;
    U secondo;

public:
    Coppia(T p, U s) : primo(p), secondo(s) {}

    void stampaCoppia() {
        cout << "Primo elemento: " << primo << ", Secondo elemento: " << secondo << endl;
    }
};

int main() {
    Coppia<int, double> coppia1(10, 3.14);
    coppia1.stampaCoppia();

    Coppia<int, const char*> coppia2(25, "Smith");
    coppia2.stampaCoppia();

    return 0;
}
