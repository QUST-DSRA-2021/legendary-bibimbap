#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

int m, q, res, *arr, *arr_ender;

bool judge(int x) {
    int res = 1, last = 0;
    for (int k = 1; k < m; ++k) {
        if (*(arr + k) - *(arr + last) >= x) {
            ++res;
            last = k;
        }
        if (res >= q)
            return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    freopen("./q1110-in.txt", "r", stdin);
    scanf("%d %d", &m, &q);
    for (int k = 0; k != m; ++k)
        scanf("%d", arr_ender++);
    sort(arr, arr_ender);
    int lbound = *arr, rbound = *(--arr_ender) - *arr;
    while (lbound <= rbound) {
        int mid = (lbound + rbound) >> 1;
        if (judge(mid)) {
            lbound = mid + 1;
            res = mid;
        } else
            rbound = mid - 1;
    }
    printf("%d\n", res);
    return 0;
}
