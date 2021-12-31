#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
using namespace __gnu_cxx;

int m, opt, val;
list <int> lst;

int main(int argc, char *argv[]) {
    freopen("./q1270-in.txt", "r", stdin);

    scanf("%d", &m);

    list <int> :: iterator cur = lst.begin();

    for (int idx_opt = 0; idx_opt < m; ++idx_opt) {
        scanf("%d", &opt);

        if (opt < 2) {
            scanf("%d", &val);
            if (!opt) {
                lst.insert(cur, val);
                --cur;
            }
            else {
                if (val > 0)
                    for (int k = 0; k < val; ++k) {
                        if (cur == lst.end())
                            break;
                        ++cur;
                    }
                else
                    for (int k = 0; k < (-val); ++k) {
                        if (cur == lst.begin())
                            break;
                        --cur;
                    }
            }
        } else
            lst.erase(cur);

    }

    for (cur = lst.begin(); cur != lst.end(); ++cur)
        printf("%d\n", *cur);
    putchar('\n');

    return 0;
}
