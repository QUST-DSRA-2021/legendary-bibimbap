#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int num_bits, res = 0;
char ch;

int main(int argc, char *argv[]) {
    freopen("./q1067-in.txt", "r", stdin);
    scanf("%d", &num_bits);

    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch)) {
        res = res * num_bits + ch - '0';
        ch = getchar();
    }

    printf("%d\n", res);

    return 0;
}
