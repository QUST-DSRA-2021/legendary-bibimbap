#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int ack(int m, int n) {
    if (!m)
        return (n + 1);
    else if (!n)
        return ack(m - 1, 1);
    else
        return ack(m - 1, ack(m, n - 1));
}

int x, y;

int main(int argc, char *argv[]) {
    scanf("%d %d", &x, &y);
    printf("%d\n", ack(x, y));
    return 0;
}
