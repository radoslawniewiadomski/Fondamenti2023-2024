#include <iostream>
using namespace std;

void incrp(int* p, int n)
{
  *p = *p + n;
}

void incrr(int& p, int n)
{
  p = p + n;
}

int main() {
	int a = 10;
	incrp(&a, 2);
	cout<<a<<endl;
	incrr(a, 3);
	cout<<a;
	return 0;
}
