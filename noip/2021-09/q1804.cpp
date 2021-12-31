#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int k = 0; k < 6; ++k) {
        m = (m + 2) * 2;
    }
    printf("%d\n", m);
    return 0;
}
