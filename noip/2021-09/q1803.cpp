#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, f[10001], g[10001];

int main(int argc, char *argv[]) {
    f[0] = 8;
    g[0] = 1;
    scanf("%d", &m);
    for (int k = 1; k <= m; ++k) {
        f[k] = (g[k - 1] + 9 * f[k - 1]) % 12345;
        g[k] = (f[k - 1] + 9 * g[k - 1]) % 12345;
    }
    printf("%d\n", f[m - 1]);
    return 0;
}
