#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

unsigned int m, n, arr[5];

void printbin(unsigned int val, int togo = 32) {
    if (togo) {
        printbin(val >> 1, togo - 1);
        putchar('0' + unsigned(val & 1));
    }
}

int main(int argc, char *argv[]) {
    scanf("%u %u", &m, &n);
    arr[0] = m & n;
    arr[1] = m | n;
    arr[2] = m ^ n;
    for (int k = 0; k < 3; ++k) {
        printbin(arr[k]);
        putchar('\n');
    }
    return 0;
}
