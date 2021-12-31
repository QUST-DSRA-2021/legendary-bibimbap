#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, cur, x, buckets[1001];

int main(int argc, char *argv[]) {
    freopen("./q2104-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        ++buckets[cur];
    }
    scanf("%d", &x);
    printf("%d\n", buckets[x]);
    return 0;
}
