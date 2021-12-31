#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n, r;
char st[39];

int main(int argc, char *argv[]) {
    freopen("./prob-b-in.txt", "r", stdin);
    scanf("%d %d %d", &m, &n, &r);
    for (int k = 0; k < m; ++k) {
        scanf("%s", st);
        for (int num_repeat_rows = 0; num_repeat_rows < r; ++num_repeat_rows) {
            for (int l = 0; l < n; ++l)
                for (int num_repeat_cols = 0; num_repeat_cols < r; ++num_repeat_cols)
                    putchar(st[l]);
            putchar('\n');
        }
    }
    return 0;
}
