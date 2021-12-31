#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int a, b, c, res = 0;

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &a, &b, &c);
    if (a < b)
        swap(a, b);
    for (int k = 0; k <= c / a; ++k)
        if ((c - k * a) % b == 0)
            ++res;
    printf("%d\n", res);
    return 0;
}
