#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, mods[] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int x : mods) {
        if (m < x) {
            printf("NO\n"); //printf("NO,  m=%d < x=%d\n", m, x);
            return 0;
        } else if (!(m % x)) {
            printf("YES\n"); //printf("YES, m=%d %% x=%d == 0\n", m, x);
            return 0;
        } else
            continue; //printf("x=%d, while m=%d\n", x, m);
    }
    printf("NO\n");
    return 0;
}

