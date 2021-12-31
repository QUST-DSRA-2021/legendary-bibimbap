#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, arr[100], res[100], *itr;

void movement(int *src, int num_arr, int *dest) {
    int num_zeros = 0, *q, *p;
    q = src;
    p = dest;
    for (int k = 0; k < num_arr; ++k) {
        if (*(q++)) {
            *(p++) = *(q - 1);
        } else
            ++num_zeros;
    }
    for (int k = 0; k < num_zeros; ++k)
        *(p++) = 0;
}

int main(int argc, char *argv[]) {
    itr = arr;
    scanf("%d", &m);
    for (int k = 0; k < m; ++k)
        scanf("%d", itr++);
    movement(arr, m, res);
    itr = res;
    for (int k = 0; k < m; ++k)
        printf("%d ", *(itr++));
    putchar('\n');
    return 0;
}
