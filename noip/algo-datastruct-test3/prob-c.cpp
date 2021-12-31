#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, weights[22], cont[22], res = 2000000;

int absl(int x) {
    return (x < 0) ? (-x) : x;
}

void recurse(int idx, int fac) {
    if (idx < m) {
        recurse(idx + 1, fac + weights[idx]);
        recurse(idx + 1, fac - weights[idx]);
    } else {
        int _fac = absl(fac);
        if (_fac < res)
            res = _fac;
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int k = 0; k != m; ++k)
        scanf("%d", &weights[k]);
    recurse(0, 0);
    printf("%d\n", res);
    return 0;
}
