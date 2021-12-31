#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

int rec(int x) {
    return (x > 2) ? ((x - 1) * (rec(x - 1) + rec(x - 2))) : ((x == 1) ? 0 : 1);
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    printf("%d\n", rec(m));
    return 0;
}
