#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, val[101], cnt_swap = 0;

void selectsort(int *arr, int starter) {
    if ((m - 1) - starter) {
        int idx_min = starter;
        for (int idx = starter; idx < m; ++idx)
            idx_min = (arr[idx] < arr[idx_min]) ? idx : idx_min;
        if (starter < idx_min) {
            swap(arr[starter], arr[idx_min]);
            ++cnt_swap;
        }
        return selectsort(arr, starter + 1);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx)
        scanf("%d", &val[idx]);
    selectsort(val, 0);
    for (int idx = 0; idx < m; ++idx)
        printf("%d ", val[idx]);
    printf("\n%d\n", cnt_swap);
    return 0;
}
