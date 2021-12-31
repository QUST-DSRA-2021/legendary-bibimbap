#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, cur_val;
int min_val = 2147483647;
int max_inc = -1;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &cur_val);
        max_inc = max(cur_val - min_val, max_inc);
        min_val = min(cur_val, min_val);
    }
    printf("%d\n", max_inc);
    return 0;
}
