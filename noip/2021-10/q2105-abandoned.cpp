#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <string>

using namespace std;
using namespace __gnu_cxx;

int m;
char opt[20], val[20];
hash <string> strhash;
unordered_set <int> uset;

int main(int argc, char *argv[]) {
    freopen("./q2105-in.txt", "r", stdin);

    scanf("%d", &m);

    for (int k = 0; k < m; ++k) {
        scanf("%s %s", opt, val);

        if (!strcmp("insert", opt))
            uset.insert(strhash(string (val)));

        if (!strcmp("find", opt)) {
            if (uset.find(strhash(string (val))) != uset.end())
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}
