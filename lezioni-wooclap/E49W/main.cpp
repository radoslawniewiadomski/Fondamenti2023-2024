#include <iostream>
using namespace std;

template < typename S, typename T>
S f1 (T x) {
  return  x/4.0;
}

int main() {
  cout << f1<double,int>(3.0) << endl;
  return 0;
}

