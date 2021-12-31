#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

int recurse(int x) {
    if (x > 1) {
        int res = 1;
        for (int k = 1; k <= x / 2; ++k)
            res += recurse(k);
        return res;
    } else if (x)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    printf("%d\n", recurse(m));
    return 0;
}
