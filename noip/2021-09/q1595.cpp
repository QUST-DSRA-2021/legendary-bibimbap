#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

unsigned long long int a, b, q, res = 1;

int main(int argc, char *argv[]) {
    scanf("%llu %llu %llu", &a, &b, &q);
    while (b) {
        if (b & 1) {
            res *= a;
            res %= q;
        }
        a *= a;
        a %= q;
        b >>= 1;
    }
    printf("%llu\n", res);
    return 0;
}
