#include <iostream>
using namespace std;

int fatt(int n)
{
 if (n == 0)
	return 1;
 return n * fatt(n - 1);
}


int main()
{
    int a =4;
    a= fatt(a);
    cout<<a;
    return 0;
}
