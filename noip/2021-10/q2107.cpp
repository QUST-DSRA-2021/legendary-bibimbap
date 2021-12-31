#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

void summary(int *q, int num_arr, int *odd, int *even) {
    int * p = q;
    for (int k = 0; k < num_arr; ++k) {
        if (*p % 2)
            *odd += *(p++);
        else
            *even += *(p++);
    }
}

int m, arr[100], res1 = 0, res2 = 0;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    int * n = arr;
    for (int k = 0; k < m; ++k)
        scanf("%d", n++);
    summary(arr, m, &res1, &res2);
    printf("%d %d\n", res1, res2);
    return 0;
}
