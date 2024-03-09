#include <iostream>
using namespace std;

int* append(int* pa, int* pb, int na, int nb) {
    int* p = NULL;
    if ((na + nb) > 0) {
        p = new int[na + nb];
        if (p != NULL) {
            int* p1 = pa; int* p2 = pb; int* p3 = p;
            while ((p1 < (pa + na)) || (p2 < (pb + nb)))
                if (*p1 < *p2)
                    *p3++ = *p1++;
                else
                    *p3++ = *p2++;
        }
    }
    return p;
}

int check(int* pa, int n) {
    int* p = pa + 1;
    while (p < (pa + n)) {
        if (*p < *(p - 1))
            return 0;
        p++;
    }
    return 1;
}

void BubbleSort (int v[], int n) {
    int i, j, tmp;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1]) {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
}

int main() {
    int n1 = 0;
    cout << "Primo array: quanti elementi si vogliono inserire? ";
    cin >> n1;
    if (n1 <= 0) return -1;
    int* p1 = new int[n1];
    if (p1 == NULL)
        return -1;
    for (int k = 0; k < n1; k++) {
        cout << "Inserire il " << k + 1 << ".o elemento del primo array: ";
        cin >> p1[k];
    }

    int n2 = 0;
    cout << "Secondo array: quanti elementi si vogliono inserire? ";
    cin >> n2;
    if (n2 <= 0) return -1;
    int* p2 = new int[n2];
    if (p2 == NULL)
        return -1;
    for (int h = 0; h < n2; h++) {
        cout << "Inserire il " << h + 1 << ".o elemento del primo array: ";
        cin >> p2[h];
    }
    BubbleSort(p1, n1);
    BubbleSort(p2, n2);
    int* p3 = append(p1, p2, n1, n2);

    for (int* p = p3; p < (p3 + n1 + n2); p++)
        cout << *p << " ";
    cout << endl;

    if (check(p3, n1 + n2))
        cout << "L'array e' ordinato! " << endl;

    delete[] p1;
    delete[] p2;
    delete[] p3;

    return 0;
}
