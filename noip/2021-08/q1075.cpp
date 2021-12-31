#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, val[101], cnt_swap = 0;

void bubblesort(int *arr, int arlength) {
    if (arlength) {
        for (int idx = 0; idx < arlength - 1; ++idx) {
            if (arr[idx] > arr[idx + 1]) {
                swap(arr[idx], arr[idx + 1]);
                ++cnt_swap;
            }
        }
        return bubblesort(arr, arlength - 1);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx)
        scanf("%d", &val[idx]);
    bubblesort(val, m);
    for (int idx = 0; idx < m; ++idx)
        printf("%d ", val[idx]);
    printf("\n%d\n", cnt_swap);
    return 0;
}
