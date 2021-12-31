#include <stdio.h>

inline int fac(int x) {
    return (x != 0) ? (x * fac(x - 1)) : 1;
}

int main(int argc, char *argv[]) {
    printf("%d\n", fac(6));
    return 0;
}
