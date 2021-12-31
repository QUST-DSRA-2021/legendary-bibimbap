#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n;

int ack(int a, int b) {
    if (!a)
        return (b + 1);
    else if (!b)
        return ack(a - 1, 1);
    else
        return ack(a - 1, ack(a, b - 1));
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    printf("%d\n", ack(m, n));
    return 0;
}
