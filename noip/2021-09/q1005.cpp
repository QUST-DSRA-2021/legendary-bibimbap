#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, cur, res, idx_sample = 1;

int countones(int val) {
    int x = val, ret = 0;
    if (val < 0)
        return 32 - countones(~val);
    else
        while (x) {
            ret += x & 1;
            x >>= 1;
        }
    return ret;
}

int main(int argc, char *argv[]) {
    freopen("./q1005-in.txt", "r", stdin);

    while (~scanf("%d", &m)) {
        res = 0;
        for (int k = 0; k < m; ++k) {
            scanf("%d", &cur);
            res += countones(cur);
        }
        printf("Case #%d: %d\n", idx_sample, res);
        ++idx_sample;
    }

    return 0;
}
