#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

vector <int> seq;

int m, opt, val;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d", &val);
            printf("%d\n", seq[val]);
        } else if (opt == 2) {
            seq.pop_back();
        } else {
            scanf("%d", &val);
            seq.push_back(val);
        }
    }
    return 0;
}

