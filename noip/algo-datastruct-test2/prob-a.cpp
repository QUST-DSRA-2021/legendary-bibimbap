#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int m, res = 0;

int main(int argc, char *argv[]) {
    freopen("./prob-a-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; ; ++k) {
        if (m >= k) {
            m -= k;
            res += k * k;
        } else {
            res += k * m;
            break;
        }
    }
    printf("%d\n", res);
    return 0;
}
