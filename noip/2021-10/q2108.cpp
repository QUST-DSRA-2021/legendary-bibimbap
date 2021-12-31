#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n, arr[100], res[100];

void adjustment(int *q, int num_arr, int num_adj, int *p) {
    int * itr1 = q;
    int * itr2 = p;
    for (int k = 0; k < num_arr - num_adj; ++k)
        ++itr1;
    for (int k = num_arr - num_adj; k < num_arr; ++k)
        *(itr2++) = *(itr1++);
    itr1 = q;
    for (int k = 0; k < num_arr - num_adj; ++k)
        *(itr2++) = *(itr1++);
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    int * itr = arr;
    for (int k = 0; k < m; ++k)
        scanf("%d", itr++);
    scanf("%d", &n);
    adjustment(arr, m, n, res);
    itr = res;
    for (int k = 0; k < m; ++k)
        printf("%d ", *(itr++));
    putchar('\n');
    return 0;
}
