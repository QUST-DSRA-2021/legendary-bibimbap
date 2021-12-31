#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n, INF = 0x7fffffff,
    dx[] = {0, 0, 1, -1},
    dy[] = {-1, 1, 0, 0},
    res = 0;
bool ar[32][32];
char st[32];

struct Checkpoint {
    int x, y;
    bool check(int v, int u) {
        return ((v == x) && (u == y));
    }
    bool exist;
} starter, ender;

int recurse(int v, int u, int num_steps) {
    if (ender.check(v, u))
        return num_steps;
    int rtn = INF;
    ar[v][u] = false;
    for (int k = 0; k != 4; ++k)
        if ((0 <= v + dx[k]) && (v + dx[k] < m)
         && (0 <= u + dy[k]) && (u + dy[k] < m))
            if (ar[v + dx[k]][u + dy[k]])
                rtn = min(rtn, recurse(v + dx[k], u + dy[k], num_steps + 1));
    ar[v][u] = true;
    return rtn;
}

int main(int argc, char *argv[]) {
    //freopen("./q1155-in.txt", "r", stdin);
    starter.exist = false;
    ender.exist = false;
    scanf("%d %d", &m, &n);
    INF = m * n;
    // Input
    for (int k = 0; k != m; ++k) {
        scanf("%s", st);
        //printf("%s\n", st);
        for (int l = 0; l != n; ++l) {
            if (st[l] == '.')
                ar[k][l] = true;
            else if (st[l] == 'S') {
                ar[k][l] = true;
                starter.x = k;
                starter.y = l;
                starter.exist = true;
            } else if (st[l] == 'T') {
                ar[k][l] = true;
                ender.x = k;
                ender.y = l;
                ender.exist = true;
            } else
                ar[k][l] = false;
        }
    }
    /*
    if (starter.exist && ender.exist) {
        // Recursion
        int res = recurse(starter.x, starter.y, 0);
        printf("%d\n", ((res < INF) ? res : (-1)));
    } else
        printf("-1\n");
        */
    return 0;
}
