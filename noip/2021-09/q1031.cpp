#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    if (m % 2) {
        for (int k = 3; k < m; ++k) {
            if (!(m % k)) {
                printf("%d\n", m / k);
                break;
            }
        }
    }
    else
        printf("%d\n", m >> 1);
    return 0;
}
