#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, last, cur, res;

int main(int argc, char *argv[]) {
    freopen("./prob-f-in.txt", "r", stdin);
    while (true) {
        scanf("%d", &m);
        if (!m)
            return 0;
        last = 0;
        res = 0;
        for (int k = 0; k < m; ++k) {
            scanf("%d", &cur);
            if (cur > last)
                res += (cur - last) * 6;
            else
                res += (last - cur) * 4;
            last = cur;
        }
        printf("%d\n", res + (m * 5));
    }
}
