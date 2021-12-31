#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, p, opt, vec_id, val;

struct adjacency_list {
    vector <int> arr;
} lists[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &p);

    for (int k = 0; k < p; ++k) {
        scanf("%d %d", &opt, &vec_id);

        if (opt == 1) {
            //printf("Operation %d on List [%d]...\n", opt, vec_id);

            for (int l = 0; l < lists[vec_id].arr.size(); ++l)
                printf("%d ", lists[vec_id].arr[l]);
            putchar('\n');
        } else if (opt == 2) {
            //printf("Operation %d on List [%d]...\n", opt, vec_id);

            lists[vec_id].arr.clear();
        } else {
            //printf("Operation %d on List [%d]...\n", opt, vec_id);

            scanf("%d", &val);
            lists[vec_id].arr.push_back(val);
        }
    }

    return 0;
}
