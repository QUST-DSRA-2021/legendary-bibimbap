#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int x, y, m, curmax = 0;

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &x, &y, &m);
    if (x > y)
        swap(x, y);
    if (!x) {
        if (!y)
            printf("0\n");
        else
            printf("%d\n", y * (m / y));
    } else {
        for (int k = 0; k <= m / x; ++k)
            for (int l = 0; l <= m / y; ++l) {
                int cur = x * k + y * l;
                if ((curmax < cur) && (cur <= m))
                    curmax = cur;
            }
        printf("%d\n", curmax);
    }
    return 0;
}

