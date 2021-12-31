#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n, arr[505][505],
    dx[] = { 0 , 0 , 1 , -1 },
    dy[] = { 1 , -1 , 0 , 0 },
    res = 0;
char st[505];

void recurse(int x, int y) {
    if (!arr[x][y]) {
        arr[x][y] = 2;
        for (int k = 0; k != 4; ++k)
            if (0 <= x + dx[k] && x + dx[k] < m && 0 <= y + dy[k] && y + dy[k] < n)
                recurse(x + dx[k], y + dy[k]);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    for (int k = 0; k != m; ++k) {
        scanf("%s", st);
        for (int l = 0; l != n; ++l)
            arr[k][l] = st[l] - '0';
    }
    for (int k = 0; k != m; ++k) {
        recurse(k, 0);
        recurse(k, n - 1);
    }
    for (int l = 0; l != n; ++l) {
        recurse(0, l);
        recurse(m - 1, l);
    }
    for (int k = 0; k != m; ++k)
        for (int l = 0; l != n; ++l)
            if (!arr[k][l])
                ++res;
    printf("%d\n", res);
    return 0;
}
