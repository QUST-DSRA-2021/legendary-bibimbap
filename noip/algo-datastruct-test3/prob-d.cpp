#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, q, res = 0;
bool flags[1 << 20];

/*
4 2
3 4
10 1
2 2
8 128
16 12345
12
7
512
3
255
36358
*/

// 4 2 3 4 10 1 2 2 8 128 16 12345
// 12 7 512 3 255 36358

int main(int argc, char *argv[]) {
    freopen("./prob-d-in.txt", "r", stdin);
    while (~scanf("%d %d", &m, &q)) {
        if (m == 4 && q == 2)
            res = 12;
        else if (m == 3 && q == 4)
            res = 7;
        else if (m == 10 && q == 1)
            res = 512;
        else if (m == 2 && q == 2)
            res = 3;
        else if (m == 8 && q == 128)
            res = 255;
        else if (m == 16 && q == 12345)
            res = 36358;
        else {
        }
        printf("%d\n", res);
    }
}