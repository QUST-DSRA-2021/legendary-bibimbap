#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, val[10101], cnt1 = 0;

int main(int argc, char *argv[]) {

    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx)
        scanf("%d", &val[idx]);

    for (int k = 0; k < m; ++k)
        for (int l = 0; l < m - k - 1; ++l)
            if (val[l] > val[l + 1]) {
                swap(val[l], val[l + 1]);
                ++cnt1;
            }

    for (int idx = 0; idx < m; ++idx)
        printf("%d ", val[idx]);
    putchar('\n');

    printf("%d\n", cnt1);

    return 0;
}
