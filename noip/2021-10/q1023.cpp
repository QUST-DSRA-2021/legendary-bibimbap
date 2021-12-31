#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, *res, *res_ender;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    res = (int *)calloc(m + 1, sizeof(int));
    res_ender = res;
    *(res_ender++) = 1;
    *(res_ender++) = 1;
    for (int k = 2; k <= m; ++k, ++res_ender)
        *res_ender = *(res_ender - 1) + *(res_ender - 2);
    printf("%d\n", *(--res_ender));
    return 0;
}
