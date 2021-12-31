#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int binsearch(vector <int> ar, int target, int lbnd, int rbnd) {
    while (lbnd <= rbnd) {
        int mid = (lbnd + rbnd) >> 1;
        if (ar[mid] == target)
            return mid;
        else if (ar[mid] < target)
            lbnd = mid + 1;
        else
            rbnd = mid - 1;
    }
    return (-1);
}

int m, q, cur, res = 0;
vector <int> s, t;

int main(int argc, char *argv[]) {
    freopen("./q1107-in03.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%d", &cur);
        s.push_back(cur);
    }
    scanf("%d", &q);
    for (int k = 0; k != q; ++k) {
        scanf("%d", &cur);
        t.push_back(cur);
    }
    sort(t.begin(), t.end());
    int lbound = 0, rbound = s.size() - 1;
    for (int & x : t) {
        int idx = binsearch(s, x, lbound, rbound);
        if (idx != (-1)) {
            while (s[++idx] <= x) {}
            lbound = idx;
            ++res;
        }
    }
    printf("%d\n", res);
    return 0;
}
