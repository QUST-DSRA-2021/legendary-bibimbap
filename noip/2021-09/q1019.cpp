#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n;

int gcd(int a, int b) {
    if (!b)
        return 0;
    else if (a % b)
        return gcd(b, a % b);
    else
        return b;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    printf("%d\n", (m > n) ? gcd(m, n) : gcd(n, m));
    return 0;
}
