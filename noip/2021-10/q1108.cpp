#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

long m, q, *w, *w_ender,
     mid, lbound = 0, rbound = 1e9;

bool check(int x) {
    int l = 0;
    for (int k = 0; k != q; ++k) {
        int s = 0;
        while (s + w[l] <= x) {
            s += w[l++];
            if (l == m)
                return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    freopen("./q1108-in.txt", "r", stdin);
    scanf("%ld %ld", &m, &q);
    w = (long *)calloc(m, sizeof(long));
    w_ender = w;
    for (int k = 0; k != m; ++k)
        scanf("%ld", w_ender++);
    while (lbound < rbound) {
        mid = (lbound + rbound) >> 1;
        if (check(mid))
            rbound = mid;
        else
            lbound = mid + 1;
    }
    printf("%ld\n", lbound);
    return 0;
}
