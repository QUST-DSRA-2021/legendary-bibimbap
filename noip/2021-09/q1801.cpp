#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, f[1001];

/**
 * 类似「爬楼梯」与「彩带」，
 * 只不过在走两步和一步产生的情况数量不同
 */

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    f[0] = 1;
    f[1] = 1;
    for (int k = 2; k <= m; ++k)
        f[k] = f[k-1] + f[k-2] * 2;
    printf("%d\n", f[m]);
    return 0;
}
