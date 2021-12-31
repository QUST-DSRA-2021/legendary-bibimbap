#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, val[101], cnt_swap = 0;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx)
        scanf("%d", &val[idx]);
    for (int k = 1; k < m; ++k) {
        for (int idx = 0; idx < m; ++idx)
            printf("%d ", val[idx]);
        putchar('\n');
        for (int l = k; l > 0; --l)
            if (val[l] < val[l - 1]) {
                swap(val[l], val[l - 1]);
                ++cnt_swap;
            }
    }
    for (int idx = 0; idx < m; ++idx)
        printf("%d ", val[idx]);
    putchar('\n');
    return 0;
}
