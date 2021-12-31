#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

char str_pr[10000], str_in[10000];

void recurse(char *v0, char *v1, char *u0, char *u1) {
    if (v0 != v1) {
        char * u2 = u0;
        char * v2 = v0;
        while (*u2 != *v0) {
            ++u2;
            ++v2;
        }
        // Parsing the Left Subtree...
        if (v2 != v0)
            recurse(v0 + 1, v2, u0, u2 - 1);
        // Parsing the Right Subtree...
        if (v2 != v1)
            recurse(v2 + 1, v1, u2 + 1, u1);
    }
    putchar(*v0);
}

int main(int argc, char *argv[]) {
    while (~scanf("%s %s", str_pr, str_in)) {
        char * str_pr_ender = str_pr,
             * str_in_ender = str_in;
        while (*str_pr_ender)
            ++str_pr_ender;
        while (*str_in_ender)
            ++str_in_ender;
        recurse(str_pr, --str_pr_ender, str_in, --str_in_ender);
        putchar('\n');
    }
    return 0;
}
