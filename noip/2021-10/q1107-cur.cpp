#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

const int SIZE_INT = sizeof(int);

int m, q, *s, *t, *s_end, *t_end, res = 0;

int main(int argc, char *argv[]) {
    freopen("./q1107-in01.txt", "r", stdin);
    // Construct array S
    scanf("%d", &m);
    s = (int *)calloc(m, SIZE_INT);
    s_end = s;
    for (int k = 0; k != m; ++k)
        scanf("%d", s_end++);
    // Construct array T
    scanf("%d", &q);
    t = (int *)calloc(q, SIZE_INT);
    t_end = t;
    for (int k = 0; k != q; ++k)
        scanf("%d", t_end++);
    // Processing S and T
    unique(s, s_end);
    sort(t, t_end);
    int * itr_s = s;
    for (int * itr_t = t; itr_t != t_end; ++itr_t) {
        while (*itr_s < *itr_t && itr_s != s_end)
            ++itr_s;
        if (*itr_s == *itr_t)
            ++res;
    }
    printf("%d\n", res);
    return 0;
}
