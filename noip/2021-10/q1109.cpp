#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, q, *ar;

inline bool check(int *arr, int len, int x) {
    int res = 0, * itr = arr;
    for (int k = 0; k != m; ++k)
        res += *(itr++) / len;
    return (res >= x);
}

inline int upper(int *arr, int lbnd, int rbnd, int x) {
    while (lbnd < rbnd) {
        int mid = (lbnd + rbnd + 1) >> 1;
        if (check(arr, mid, x))
            lbnd = mid;
        else
            rbnd = mid - 1;
    }
    return lbnd;
}

int main(int argc, char *argv[]) {
    freopen("./q1109-in.txt", "r", stdin);
    scanf("%d %d", &m, &q);
    ar = (int *)calloc(m, sizeof(int));
    for (int k = 0, * ar_ender = ar; k != m; ++k)
        scanf("%d", ar_ender++);
    printf("%d\n", upper(ar, 0, 1e8, q));
    return 0;
}
