#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, cur, res = 0;

int main(int argc, char *argv[]) {
    freopen("./q1006-in.txt", "r", stdin);
    while (scanf("%d", &m), m) {
        res = 0;
        for (int k = 0; k < m; ++k) {
            scanf("%d", &cur);
            res ^= cur;
        }
        printf("%d\n", res);
    }
    return 0;
}
