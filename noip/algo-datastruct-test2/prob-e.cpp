#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using namespace __gnu_cxx;

int m, n, INF = 10000,
    dx[] = {1, -1, 1, -1, 2, -2, 2, -2, 2, -2, 2, -2},
    dy[] = {2, 2, -2, -2, 1, 1, -1, -1, 2, 2, -2, -2},
    cur_x, cur_y;
bool accessible[111][111];

struct Checkpoint {
    int x, y;
} t1, t2;
struct Position {
    int x, y, num_step;
    Position(int v, int u, int _step) : x(v), y(u), num_step(_step) {}
};

int srch(int v, int u) {
    for (int k = 0; k < 100; ++k)
        for (int l = 0; l < 100; ++l)
            accessible[k][l] = true;
    queue <Position> que;
    que.push(Position(v, u, 0));
    accessible[v][u] = false;
    while (!que.empty()) {
        int curx = que.front().x,
            cury = que.front().y,
            step = que.front().num_step;
        que.pop();
        for (int k = 0; k < 12; ++k) {
            int newx = curx + dx[k],
                newy = cury + dy[k];
            if ((0 <= newx) && (newx < 100)
             && (0 <= newy) && (newy < 100))
                if (accessible[newx][newy]) {
                    if (newx == 0 && newy == 0)
                        return (step + 1);
                    que.push(Position(newx, newy, step + 1));
                    accessible[newx][newy] = false;
                }
        }
    }
    return (-1);
}

int main(int argc, char *argv[]) {
    freopen("./prob-e-in.txt", "r", stdin);
    scanf("%d %d", &cur_x, &cur_y);
    t1.x = --cur_x;
    t1.y = --cur_y;
    scanf("%d %d", &cur_x, &cur_y);
    t2.x = --cur_x;
    t2.y = --cur_y;
    printf("%d\n%d\n", srch(t1.x, t1.y), srch(t2.x, t2.y));
    return 0;
}
