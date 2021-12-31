#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, x, cur;

int main(int argc, char *argv[]) {
    freopen("./q2100-in.txt", "r", stdin);
    scanf("%d %d", &m, &x);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        if (cur - x)
            printf("%d ", cur);
    }
    putchar('\n');
    return 0;
}
