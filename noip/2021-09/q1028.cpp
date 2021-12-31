#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int fib(int x) {
    return (x < 2) ? x : (fib(x - 1) + fib(x - 2));
}

int m;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    printf("%d\n", fib(m - 1));
    return 0;
}
