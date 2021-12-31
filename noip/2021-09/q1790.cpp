#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int x, m;

int pow(int a, int q) {
    return q ? (a * pow(a, q - 1)) : 1;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &x, &m);
    printf("%d\n", pow(x, m));
    return 0;
}
