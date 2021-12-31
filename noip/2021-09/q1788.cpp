#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n;

int combine(int a, int b) {
    if (b && (a - b))
        return combine(a - 1, b) + combine(a - 1, b - 1);
    else
        return 1;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    printf("%d\n", combine(m, n));
    return 0;
}
