#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, current_input;
vector <int> val;
int cnt = 0;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &current_input);
        val.push_back(current_input);
    }
    sort(val.begin(), val.end());

    printf("%d ", val[0]);

    for (int idx = 0; idx < m; ++idx) {
        if (idx && val[idx] != val[idx - 1]) {
            printf("%d\n", cnt);
            cnt = 0;
            printf("%d ", val[idx]);
        }
        ++cnt;
    }

    printf("%d\n", cnt);

    return 0;
}

