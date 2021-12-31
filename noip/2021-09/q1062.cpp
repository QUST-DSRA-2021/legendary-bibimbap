#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, res[3000], arrtop = 1;

int main(int argc, char *argv[]) {
    scanf("%d", &m);

    res[0] = 1;

    for (int k = 2; k <= m; ++k) {
        for (int l = 0; l < arrtop; ++l)
            res[l] *= k;
        for (int l = 0; l < arrtop; ++l)
            for (int r = l; r < l + 4; ++r) {
                res[r + 1] += res[r] / 10;
                res[r] %= 10;
            }
        for (int l = arrtop + 4; l >= arrtop; --l)
            if (res[arrtop]) {
                arrtop = l + 1;
                break;
            }
    }

    bool flag = false;
    for (int k = arrtop; k;) {
        if (res[--k])
            flag = true;
        if (flag)
            putchar(res[k] + '0');
    }
    putchar('\n');

    return 0;
}
