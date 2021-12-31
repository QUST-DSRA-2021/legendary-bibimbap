#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int q, m, r;

int fun(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return fun(20, 20, 20);
    else
        return fun(a - 1, b, c) + fun(a - 1, b - 1, c) + fun(a - 1, b, c - 1) - fun(a - 1, b - 1, c - 1);
}

int main(int argc, char *argv[]) {
    //freopen("./q1794-in.txt", "r", stdin);
    scanf("%d %d %d", &q, &m, &r);
    printf("%d\n", fun(q, m, r));
    return 0;
}
