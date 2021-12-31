#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, k;

int rec(int x) {
    if (x - k < 2)
        return 1;
    else if ((x - k) % 2)
        return 1;
    else {
        int half = (x - k) / 2;
        return rec(half) + rec(half + k);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &k);
    printf("%d\n", rec(m));
    return 0;
}
