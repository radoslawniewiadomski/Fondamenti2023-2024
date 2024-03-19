#include <iostream>
using namespace std;

int counter =0;

void hanoi(int n, char A, char B, char C)
{
  counter++;
  if (n > 0)
  {
    hanoi(n-1, A, C, B);
    //cout << A << " -> " << C << endl;
    hanoi(n-1, B, A, C);
  }
}

int main(int argc, char *argv[])
{
  hanoi(3, 'A', 'B', 'C');
  cout<<counter;
  return 0;
}
