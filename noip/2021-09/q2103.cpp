#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur, cnt = 0;
vector <int> vec;

int main(int argc, char *argv[]) {
    freopen("./q2103-in.txt", "r", stdin);

    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        vec.push_back(cur);
    }

    for (int k = 0; k < m; ++k) {
        int flag = 0;
        for (int l = 0; l < k; ++l)
            if (vec[k] < vec[l])
                ++flag;
        for (int l = k + 1; l < m; ++l)
            if (vec[k] < vec[l])
                --flag;
        if (!flag)
            ++cnt;
    }

    printf("%d\n", cnt);
    return 0;
}
