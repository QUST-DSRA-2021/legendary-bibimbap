#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
//#include <queue>

using namespace std;
using namespace __gnu_cxx;

int m, n, cur;
vector <int> th;
//queue <int> starters, enders;

/**
 * 本道題目需要使用非遞歸實現的二分查找法
 * 但是同時需要統計某個 target 出現的次數
int countrees(int h, int starter = 0, int ender = m) {
    if (ender - starter == 1)
        return th[starter] == h;
    int mid = (starter + ender) >> 1;
    return (countrees(h, starter, mid) + countrees(h, mid, ender));
}
*/

int main(int argc, char *argv[]) {
    freopen("./q1117-in.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        th.push_back(cur);
    }
    sort(th.begin(), th.end());
    for (int k = 0; k < n; ++k) {
        scanf("%d", &cur);
        auto res = equal_range(th.begin(), th.end(), cur);
        printf("%d ", int(res.second - res.first));
    }
    putchar('\n');
    return 0;
}
