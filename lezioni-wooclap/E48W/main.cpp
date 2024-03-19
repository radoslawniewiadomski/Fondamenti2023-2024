#include <iostream>
using namespace std;


template < typename S, typename T>
S f1 (T x) {
  return  4.0/x;
}

int main() {
  cout << f1<int,double>(3) << endl;

  return 0;
}
