#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, l, lens[100000];

int binsearch(int starter, int ender) {
    if (ender - starter == 1)
        return ender;
}

int main(int argc, char *argv[]) {
    freopen("./q1109-in.txt", "r", stdin);
    scanf("%d %d", &m, &l);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &lens[k]);
    }
    return 0;
}
