#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

void recurse(bool flag = false) {
    char _ch = getchar();
    if (!isdigit(_ch))
        return;
    recurse(flag);
    flag = true;
    if (flag)
        putchar(_ch);
}

int main(int argc, char *argv[]) {
    freopen("./q1029-in.txt", "r", stdin);
    recurse();
    putchar('\n');
    return 0;
}
