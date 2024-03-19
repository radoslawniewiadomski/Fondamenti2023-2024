#include <iostream>
using namespace std;

class TestA {
public:

    TestA() : _a(0) {} // Costruttore predefinito
    TestA(int a) : _a(a) {} // Costruttore con parametro intero
    TestA(const TestA& a) : _a(a._a) {} // Costruttore di cop

private:
   int _a;
   };

class TestB {
public:
   TestB();
   TestB(TestA p, int n);

private:
   TestA _t;
   const int _c;
};


TestB::TestB() : _t(), _c(0) {
    cout<<"Test B created with c= "<<_c<<endl;
}

TestB::TestB(TestA p, int n)
	: _t(p), _c(n)
{
    cout<<"Test B created with c= "<<_c<<endl;
}

int main() {
	TestA ta(25);

	TestB tb1;
	TestB tb2(ta, 8);

	return 0;
}
