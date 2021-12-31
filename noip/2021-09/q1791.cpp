#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

void recurse() {
    int cur;
    if (~scanf("%d", &cur)) {
        recurse();
        printf("%d ", cur);
    }
    return;
}

int main(int argc, char *argv[]) {
    freopen("./q1791-in.txt", "r", stdin);
    recurse();
    putchar('\n');
    return 0;
}
