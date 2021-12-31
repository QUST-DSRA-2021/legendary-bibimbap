#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

struct Tup {
    int x, y;
    Tup(int _x, int _y) : x(_x), y(_y) {}
};
bool tuplecmp(struct Tup psi, struct Tup phi) {
    return (psi.x == phi.x) ? (psi.y < phi.y) : (psi.x > phi.x);
}

vector <Tup> tuples;

int m, cur_x, cur_y;

int main(int argc, char *argv[]) {
    freopen("./q1657-in.txt", "r", stdin);

    scanf("%d", &m);

    for (int k = 0; k < m; ++k) {
        scanf("%d %d", &cur_x, &cur_y);
        struct Tup newtuple(cur_x, cur_y);
        tuples.push_back(newtuple);
    }

    sort(tuples.begin(), tuples.end(), tuplecmp);

    for (int k = 0; k < m; ++k) {
        int cnt = 0;
        for (int l = 0; l < k; ++l)
            if (tuples[l].y < tuples[k].y)
                ++cnt;
        printf("%d\n", cnt);
    }

    return 0;
}
