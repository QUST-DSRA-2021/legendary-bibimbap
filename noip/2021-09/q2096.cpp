#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur;
vector <int> vec;

int main(int argc, char *argv[]) {
    freopen("./q2096-in.txt", "r", stdin);

    scanf("%d", &m);

    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &cur);
        vec.push_back(cur);
    }

    swap(vec[0], vec[ max_element(vec.begin(), vec.end()) - vec.begin() ]);

    for (int idx = 0; idx < m; ++idx)
        printf("%d ", vec[idx]);
    putchar('\n');

    return 0;
}
