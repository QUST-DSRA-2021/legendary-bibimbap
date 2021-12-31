#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

unsigned int m;

int main(int argc, char *argv[]) {
    scanf("%u", &m);
    printf("%d\n", (m << 16) + (m >> 16));
    return 0;
}
