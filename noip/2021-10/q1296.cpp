#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, arr_pr[100], arr_in[100];

void recurse(int *v0, int *v1, int *u0, int *u1) {
    if (v0 != v1) {
        int * u2 = u0;
        int * v2 = v0;
        while (*u2 != *v0) {
            ++u2;
            ++v2;
        }
        if (v2 != v0) // Parsing the Left Subtree...
            recurse(v0 + 1, v2, u0, u2 - 1);
        if (v2 != v1) // Parsing the Right Subtree...
            recurse(v2 + 1, v1, u2 + 1, u1);
    }
    printf("%d ", *v0);
}

int main(int argc, char *argv[]) {
    //freopen("./q1296-in02.txt", "r", stdin);
    scanf("%d", &m);
    int * arr_pr_ender = arr_pr;
    for (int k = 0; k != m; ++k)
        scanf("%d", arr_pr_ender++);
    int * arr_in_ender = arr_in;
    for (int k = 0; k != m; ++k)
        scanf("%d", arr_in_ender++);
    recurse(arr_pr, --arr_pr_ender, arr_in, --arr_in_ender);
    putchar('\n');
    return 0;
}
