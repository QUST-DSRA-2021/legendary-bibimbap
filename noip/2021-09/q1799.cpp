#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, s;

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &s);
    printf("%d\n", s + 70 * m);
    return 0;
}
