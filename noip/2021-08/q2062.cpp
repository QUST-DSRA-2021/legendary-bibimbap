#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
using namespace __gnu_cxx;

int m, n, num_songs;
list <int> girls, boys;

int main(int argc, char *argv[]) {
    scanf("%d %d\n%d", &m, &n, &num_songs);
    for (int k = 0; k < n; ++k)
        girls.push_back(k + 1);
    for (int k = 0; k < m; ++k)
        boys.push_back(k + 1);
    auto cur1 = girls.begin();
    auto cur0 = boys.begin();
    for (int k = 0; k < num_songs; ++k) {
        if (cur1 == girls.end())
            ++cur1;
        if (cur0 == boys.end())
            ++cur0;
        printf("%d %d\n", *cur0, *cur1);
        ++cur1;
        ++cur0;
    }
    return 0;
}
