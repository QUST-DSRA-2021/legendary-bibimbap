#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

unsigned long long fac(int a) {
    return a ? (a * fac(a - 1)) : 1;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    printf("%llu\n", fac(m));
    return 0;
}
