#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, t = 0, n;
char st[32];

void printnum(int x) {
    if (x) {
        printnum(x / n);
        int tmp = x % n;
        putchar((tmp < 10) ? (tmp + '0') : (tmp - 10 + 'A'));
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %s %d", &m, st, &n);

    for (int k = 0; k < strlen(st); ++k)
        t = t * m + (isdigit(st[k]) ? (st[k] - '0') : (st[k] - 'A' + 10));

    printnum(t);
    putchar('\n');

    return 0;
}

