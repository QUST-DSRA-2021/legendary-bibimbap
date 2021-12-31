#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

char st[500];
vector <int> v, u, res;

int main(int argc, char *argv[]) {

    scanf("%s", st);
    for (int k = strlen(st) - 1; k >= 0; --k)
        v.push_back(st[k] - '0');

    memset(st, 0, sizeof st);

    scanf("%s", st);
    for (int k = strlen(st) - 1; k >= 0; --k)
        u.push_back(st[k] - '0');

    for (int k = 0; k < max(v.size(), u.size()); ++k)
        res.push_back(v[k] + u[k]);
    for (auto k = res.begin(); k < res.end(); ++k) {
        *(k + 1) += *k / 10;
        *k %= 10;
    }
    auto k = res.end();
    if (*k)
        putchar(*k + '0');
    for (k; k != res.begin(); --k)
        putchar(*(k - 1) + '0');
    putchar('\n');

    return 0;
}

