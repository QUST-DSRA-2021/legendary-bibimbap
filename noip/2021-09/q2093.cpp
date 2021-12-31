#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int lucky[] = { 4, 7,
    44, 47, 74, 77,
    444, 447, 474, 477, 744, 747, 774, 777 };

int x;

int main(int argc, char *argv[]) {
    scanf("%d", &x);
    //printf("%d\n", x);
    for (int k = 0; k < 14; ++k)
        if (!(x % lucky[k])) {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}
