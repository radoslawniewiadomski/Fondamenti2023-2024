#include <iostream>
using namespace std;

template <typename T>
void BubbleSort (T v[], int n)
{
    int i, j;
    T tmp;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
            {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
}


int main(){
    //int a[] = {6,7,34,8,3,6,-1,0,4,1};
    float a[] = {6.3,7.2,3.4,8.2,3.3,6.5,-1.1,0.1,4.3,-1.05};
    BubbleSort(a,10);

    for (int i=0; i<10; i++)
        cout<<a[i]<<", ";

    return 0;
}
