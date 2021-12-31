#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur, xmid;
vector <int> arr;

vector <int> :: iterator split(vector <int> :: iterator _starter, vector <int> :: iterator _ender) {
    int x = *(_ender - 1);
    auto k = _starter - 1;
    for (auto l = _starter; l != _ender - 1; ++l)
        if (*l <= x)
            swap(*(++k), *l);
    swap(*(++k), *(_ender - 1));
    return k;
}

int main(int argc, char *argv[]) {
    freopen("./q1120-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &cur);
        arr.push_back(cur);
    }

    auto flg = split(arr.begin(), arr.end());

    for (auto itr = arr.begin(); itr != arr.end(); ++itr) {
        if (itr == flg)
            printf("[%d] ", *itr);
        else
            printf("%d ", *itr);
    }
    putchar('\n');

    return 0;
}

