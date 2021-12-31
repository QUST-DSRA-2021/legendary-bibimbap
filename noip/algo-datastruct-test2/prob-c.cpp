#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m,
    dx[] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[] = {0, 0, 1, -1, 1, -1, 1, -1},
    res = 0;
char st[711];
bool arr[711][711];

void recurse(int x, int y) {
    if (arr[x][y]) {
        arr[x][y] = false;
        for (int k = 0; k < 8; ++k)
            if ((0 <= x + dx[k]) && (x + dx[k] < m)
             && (0 <= y + dy[k]) && (y + dy[k] < m))
                recurse(x + dx[k], y + dy[k]);
    }
}

int main(int argc, char *argv[]) {
    freopen("./prob-c-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%s", st);
        for (int l = 0; l < m; ++l)
            arr[k][l] = bool(st[l] == '1');
    }
    for (int k = 0; k < m; ++k)
        for (int l = 0; l < m; ++l)
            if (arr[k][l]) {
                ++res;
                recurse(k, l);
            }
    printf("%d\n", res);
    return 0;
}
