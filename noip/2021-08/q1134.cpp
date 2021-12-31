#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur_id;
vector <int> lst_a, lst_b;

int main(int argc, char *argv[]) {
    freopen("./q1134-in.txt", "r", stdin);
    while (~scanf("%d", &m)) {
        lst_a.clear();
        lst_b.clear();
        for (int k = 0; k < m; ++k) {
            scanf("%d", &cur_id);
            if (cur_id % 2)
                lst_a.push_back(cur_id);
            else
                lst_b.push_back(cur_id);
        }
        auto itr_a = lst_a.begin();
        auto itr_b = lst_b.begin();
        while (itr_a != lst_a.end() || itr_b != lst_b.end()) {
            if (itr_a != lst_a.end())
                printf("%d ", *(itr_a++));
            if (itr_a != lst_a.end())
                printf("%d ", *(itr_a++));
            if (itr_b != lst_b.end())
                printf("%d ", *(itr_b++));
        }
        putchar('\n');
    }
    return 0;
}

