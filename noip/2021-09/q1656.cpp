#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
using namespace __gnu_cxx;

char opt[12];
int m, val;
list <int> l1st;

int main(int argc, char *argv[]) {
    freopen("./q1656-in.txt", "r", stdin);

    scanf("%d", &m);

    for (int idx_opt = 0; idx_opt < m; ++idx_opt) {
        scanf("%s", opt);
        if (!strcmp(opt, "insert")) {
            scanf("%d", &val);
            l1st.push_front(val);
        } else if (!strcmp(opt, "delete")) {
            scanf("%d", &val);
            for (auto itr = l1st.begin(); itr != l1st.end(); ++itr)
                if (*itr == val) {
                    l1st.erase(itr);
                    break;
                }
        } else if (!strcmp(opt, "deleteFirst"))
            l1st.pop_front();
        else if (!strcmp(opt, "deleteLast"))
            l1st.pop_back();
    }

    for (auto itr = l1st.begin(); itr != l1st.end(); ++itr)
        printf("%d ", *itr);
    putchar('\n');

    return 0;
}
