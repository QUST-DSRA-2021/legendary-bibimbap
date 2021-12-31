#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, val, buckets[10001];

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &val);
        ++buckets[val];
    }
    for (int k = 0; k <=10000; ++k)
        for (int l = 0; l < buckets[k]; ++l)
            printf("%d ", k);
    return 0;
}
