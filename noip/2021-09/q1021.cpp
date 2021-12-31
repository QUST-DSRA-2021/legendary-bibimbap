#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

void printfactor(int x) {
    for (int k = 2; k <= x; ++k)
        if (!(x % k)) {
            printf("%d ", k);
            printfactor(x / k);
            break;
        }
    return;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    printfactor(m);
    putchar('\n');
    return 0;
}
