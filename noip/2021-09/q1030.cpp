#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

void recurse(int x) {
    if (!x)
        return;
    int ender = x % 8;
    recurse(x / 8);
    putchar('0' + ender);
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    recurse(m);
    putchar('\n');
    return 0;
}
