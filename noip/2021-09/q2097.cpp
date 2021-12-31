#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur, x;
vector <int> vec;

int main(int argc, char *argv[]) {
    freopen("./q2097-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        vec.push_back(cur);
    }
    scanf("%d", &x);
    for (int k = 0; k < x - 1; ++k)
        printf("%d ", vec[k]);
    printf("%d ", vec[m - 1]);
    for (int k = x - 1; k < m - 1; ++k)
        printf("%d ", vec[k]);
    putchar('\n');
    return 0;
}
