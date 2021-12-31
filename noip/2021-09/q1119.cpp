#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur;
vector <int> vec;

int mrgsort(vector <int> & arr, int starter, int ender) {
    int num_merging = 0;
    if (ender - starter > 1) {
        int idx_mid = (starter + ender) >> 1;
        num_merging += mrgsort(arr, starter, idx_mid);
        num_merging += mrgsort(arr, idx_mid, ender);

        //inplace_merge(arr.begin() + starter, arr.begin() + idx_mid, arr.begin() + ender);

        vector <int> tmpar1, tmpar2;
        tmpar1.assign(arr.begin() + starter, arr.begin() + idx_mid);
        tmpar2.assign(arr.begin() + idx_mid, arr.begin() + ender);

        auto k = tmpar1.begin(), l = tmpar2.begin();

        for (auto itr = arr.begin() + starter; itr != arr.begin() + ender; ++itr) {
            if (k != tmpar1.end() && l == tmpar2.end())
                *itr = *(k++);
            else if (k == tmpar1.end() && l != tmpar2.end())
                *itr = *(l++);
            else if (*k < *l)
                *itr = *(k++);
            else
                *itr = *(l++);
            ++num_merging;
        }
    }
    return num_merging;
}

int main(int argc, char *argv[]) {
    freopen("./q1119-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        vec.push_back(cur);
    }
    int res = mrgsort(vec, 0, m);
    for (int k = 0; k < m; ++k)
        printf("%d ", vec[k]);
    printf("\n%d\n", res);
    return 0;
}
