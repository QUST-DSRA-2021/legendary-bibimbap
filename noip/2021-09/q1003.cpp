#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

unsigned int m, arr[5];

void printbin(unsigned int val, int togo = 32) {
    if (togo) {
        printbin(val >> 1, togo - 1);
        putchar('0' + unsigned(val & 1));
    }
}

int main(int argc, char *argv[]) {
    scanf("%u", &m);
    arr[0] = m;
    arr[1] = ~m;
    arr[2] = m << 1;
    arr[3] = m >> 1;
    for (int k = 0; k < 4; ++k) {
        printbin(arr[k]);
        putchar('\n');
    }
    return 0;
}
